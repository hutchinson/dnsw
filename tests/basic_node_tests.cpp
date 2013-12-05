#include "gtest/gtest.h"

// Project specific includes
#include "db/node.h"

// Ensure a newly created node is in the correct state.
TEST(basic_node_tests, creation)
{
  dnsw::node_ptr new_node = dnsw::node::create_node("com");

  ASSERT_TRUE(new_node.get() != NULL);
  ASSERT_TRUE(new_node.use_count() == 1);
  ASSERT_TRUE(new_node->get_parent().get() == NULL);
  ASSERT_TRUE(new_node->num_children() == 0);
  ASSERT_STREQ(new_node->get_label().c_str(), "com");
}

TEST(basic_node_tests, get_children)
{
  // Create some nodes...
  dnsw::node_ptr parent = dnsw::node::create_node("");
  dnsw::node_ptr com = dnsw::node::create_node("com");
  dnsw::node_ptr org = dnsw::node::create_node("org");
  dnsw::node_ptr gov = dnsw::node::create_node("gov");

  // Add children
  parent->add_child("com", com);
  parent->add_child("org", org);
  parent->add_child("gov", gov);

  // Check we have three children...
  ASSERT_TRUE(parent->num_children() == 3);

  ASSERT_STREQ(parent->get_child_by_name("com")->get_label().c_str(), "com");
  ASSERT_STREQ(parent->get_child_by_name("org")->get_label().c_str(), "org");
  ASSERT_STREQ(parent->get_child_by_name("gov")->get_label().c_str(), "gov");
  ASSERT_STRNE(parent->get_child_by_name("gov")->get_label().c_str(), "uk");

  ASSERT_TRUE(parent->get_child_by_name("uk").get() == NULL);
}
