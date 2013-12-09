#include "gtest/gtest.h"

#include "db/rr.h"
#include <cstring>

// Provide basic creation tests.
TEST(basic_rr_tests, creation)
{
  uint8_t my_array[16];
  memset(my_array, 'A', 16);
  dnsw::rr::rr_ptr test_ptr = dnsw::rr::rr::create_rr(dnsw::rr::A,
                                              dnsw::rr::IN,
                                              800,
                                              16,
                                              my_array);
  memset(my_array, 0, 16);

  // Test each value to confirm.
  ASSERT_TRUE(test_ptr->type == dnsw::rr::A);
  ASSERT_TRUE(test_ptr->in_class == dnsw::rr::IN);
  ASSERT_TRUE(test_ptr->ttl == 800);
  ASSERT_TRUE(test_ptr->length == 16);

  const uint8_t *ptr = test_ptr->data.get();
  for(int x = 0; x < test_ptr->length; ++x)
  {
    ASSERT_TRUE(ptr[x] == 'A');
  }
}
