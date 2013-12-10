#include "resolver/coopresolver.h"

#include <iostream>
#include <thread>
#include <utility>
#include <chrono>
#include <functional>
#include <vector>

namespace
{
  void test_function(int id, semaphore & sem)
  {
    std::cout << "test function " << id << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    sem.notify();
  }
}

dnsw::coopresolver::coopresolver()
  : m_all_threads_done(-3)
{
  std::cout << "coopresolver!" << std::endl;
}

dnsw::coopresolver::~coopresolver()
{
  std::cout << "~coopresolver" << std::endl;
}

const std::string dnsw::coopresolver::resolve(const std::string &name,
                                         dnsw::rr::TYPE record_type)
{
  std::thread t1 (test_function, 1, std::ref(m_all_threads_done));
  std::thread t2 (test_function, 2, std::ref(m_all_threads_done));
  std::thread t3 (test_function, 3, std::ref(m_all_threads_done));

  // Wait for all threads...
  std::cout << "Waiting for threads" << std::endl;

  m_all_threads_done.wait();

  t1.join();
  t2.join();
  t3.join();

  std::cout << "All Threads done..." << std::endl;

  return "";
}
