#ifndef NODE_H
#define NODE_H

// node.h
// 
// The node class represents a particular node in the DNS structure.
// Many nodes form the tree structure of the Domain Name Hierarchy.
// A node has one parent and may have many children.
// Each node as number of resource records (rr) associated with it.
//
// Required methods.
// get_label() - returns the label corresponding to this node - joining
// all labels from a given node to the root node will result in a Fully
// Qualified Domain Name (FQDN)
// get_parent() : node - returns this nodes parent.
// get_child(string) : node - return the node corresponding to the child
// label.
// get_rr(type) : vector<rr> - returns all resource records of specified
// type.
//
// node creation should be managed through a public interface which returns
// reference counted node instance thereby helping to reduce potential
// resource leaks.

// Includes
#include <memory>     // For shared_ptr

namespace dnsw
{
  // Classes
  class node
  {
    public:
     static std::shared_ptr<node> get_node(const std::string &label);

    private:
    // Construction of node classes should be private and deffered to
    // a public interface which can only return reference counted pointers
    // to node instances.
    node();
    node(const node &rhs);
    node& operator=(const node &rhs);
  };
}


#endif
