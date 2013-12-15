#ifndef COOPRESOLVER_H
#define COOPRESOVLER_H

#include "resolver/resolver.h"
#include "db/node.h"

#include <condition_variable>
#include <mutex>

namespace
{
  class semaphore
  {
    public:
      semaphore(int count = 0) : 
        count(count) { }

      void notify()
      {
        std::unique_lock<std::mutex> lck(mtx);
        ++count;
        cv.notify_one();
      }

      void wait()
      {
        std::unique_lock<std::mutex> lck(mtx);

        while(count == 0){
            cv.wait(lck);
        }
        count--;
      }

    private:
      std::mutex mtx;
      std::condition_variable cv;
      int count;
  };
}

namespace dnsw
{
  class coopresolver : public dnsw::resolver
  {
    public:
      coopresolver();
      ~coopresolver();
      const std::string resolve(const std::string &name,
                                dnsw::TYPE record_type);

    private:
      dnsw::node_ptr m_root;
  };
}

#endif
