#ifndef RR_PRINTER_H
#define RR_PRINTER_H

#include <iostream>
#include <memory>
#include <map>
#include "rr.h"

// Resource printer encapsulates the logic required for printing a
// given resource record.

namespace dnsw
{
  // rr_printer is the base class from which all other resource
  // record printers are derived.
  // They each encapuslate the logic required to display the
  // RDATA associated with them.
  class rr_printer
  {
    public:
      static rr_printer *create() { return new rr_printer(); }
      virtual void print(const dnsw::rr_ptr rr, std::ostream &out)
      {
        out << rr->ttl << "\t";
        if(rr->in_class == dnsw::IN)
          out << "IN";
        else
          out << "UNSUPPORTED CLASS";
        
        out << "\t";
      }

      virtual ~rr_printer() { };
  };

  // Default rr printer that outputs hex values of the RDATA field.
  class hex_printer : public rr_printer
  {
    public:
      static rr_printer * create()
      {
        return new hex_printer();
      }
      
      virtual void print(const dnsw::rr_ptr rr, std::ostream &out)
      {
        rr_printer::print(rr, out);
        const uint8_t *data = rr->data.get();
        for(int x = 0; x < rr->length; ++x)
        {
          out << std::hex << static_cast<uint32_t>(data[x]);
          out << " ";
        }
      }
  };

  class a_printer : public rr_printer
  {
    public:
      static rr_printer * create()
      {
        return new a_printer();
      }
      
      virtual void print(const dnsw::rr_ptr rr, std::ostream &out)
      {
        rr_printer::print(rr, out);
        out << "A" << "\t"
            << rr->data;
      }
  };

  class rr_printer_factory
  {
    public:
      static rr_printer_factory &get_factory();

      void format_rr(const dnsw::rr_ptr &rr, std::ostream &out);
      
    private:
      rr_printer_factory();
      rr_printer_factory(const rr_printer_factory &rhs);
      rr_printer_factory &operator=(const rr_printer_factory &rhs);

      typedef rr_printer* (*CreatorFunc)();
      std::map<dnsw::TYPE, CreatorFunc> classLibrary;
  };
}

#endif
