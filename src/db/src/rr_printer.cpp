#include "db/rr_printer.h"

dnsw::rr_printer_factory::rr_printer_factory()
{
  classLibrary[dnsw::A] = dnsw::a_printer::create;
}

dnsw::rr_printer_factory &dnsw::rr_printer_factory::get_factory()
{
  // TODO: Make thread safe.
  static rr_printer_factory factory;

  return factory;
}

void dnsw::rr_printer_factory::format_rr(const dnsw::rr_ptr &rr, std::ostream &out)
{
  std::map<dnsw::TYPE, CreatorFunc>::iterator it;
  it = classLibrary.find(rr->type);

  std::unique_ptr<rr_printer> printer( (it == classLibrary.end() ?
                                        dnsw::hex_printer::create() :
                                        it->second() ) );

  printer->print(rr, out);

}
