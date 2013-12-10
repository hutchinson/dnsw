#ifndef COOPRESOLVER_H
#define COOPRESOVLER_H

#include "resolver/resolver.h"
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
                                dnsw::rr::TYPE record_type);

    private:
      semaphore m_all_threads_done;
  };
}

#endif
