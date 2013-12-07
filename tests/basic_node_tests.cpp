#include "gtest/gtest.h"

// Project specific includes
#include "db/node.h"

// Ensure a newly created node is in the correct state.
TEST(basic_node_tests, creation)
{
  dnsw::node_ptr new_node = dnsw::node::create_node("com");

  ASSERT_TRUE(new_node.get() != NULL);
  ASSERT_TRUE(new_node.use_count() == 1);

  dnsw::weak_node_ptr weak_parent = new_node->get_parent();
  dnsw::node_ptr parent = weak_parent.lock();

  ASSERT_TRUE(parent.get() == NULL);
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
  dnsw::node::add_child(parent, com);
  dnsw::node::add_child(parent, org);
  dnsw::node::add_child(parent, gov);

  // Check we have three children...
  ASSERT_TRUE(parent->num_children() == 3);

  // Check each child has the correct parent.
  dnsw::weak_node_ptr w_child_com = parent->get_child_by_name("com");
  dnsw::node_ptr child_com(w_child_com.lock());
  ASSERT_STREQ(child_com->get_label().c_str(), "com");

  dnsw::weak_node_ptr w_parent_com = child_com->get_parent();
  dnsw::node_ptr parent_com(w_parent_com.lock());
  ASSERT_TRUE(parent_com.get() == parent.get());

  // --------------------------------------------------------------------------
  
  dnsw::weak_node_ptr w_child_org = parent->get_child_by_name("org");
  dnsw::node_ptr child_org(w_child_org.lock());
  ASSERT_STREQ(child_org->get_label().c_str(), "org");

  dnsw::weak_node_ptr w_parent_org = child_org->get_parent();
  dnsw::node_ptr parent_org(w_parent_org.lock());
  ASSERT_TRUE(parent_org.get() == parent.get());

  // --------------------------------------------------------------------------A
  dnsw::weak_node_ptr w_child_gov = parent->get_child_by_name("gov");
  dnsw::node_ptr child_gov(w_child_gov.lock());
  ASSERT_STREQ(child_gov->get_label().c_str(), "gov");

  dnsw::weak_node_ptr w_parent_gov = child_gov->get_parent();
  dnsw::node_ptr parent_gov(w_parent_gov.lock());
  ASSERT_TRUE(parent_gov.get() == parent.get());

  // Make sure our parent doesn't tell us it has things we don't
  ASSERT_TRUE(parent->get_child_by_name("uk").lock().get() == NULL);
}
