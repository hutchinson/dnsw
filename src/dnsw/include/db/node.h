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
#include <memory>
#include <string>
#include <map>
// TODO: Use a logger
#include <iostream>

namespace dnsw
{
  class node;
  typedef std::shared_ptr<node> node_ptr;

  // Classes
  class node
  {
    public:
     static node_ptr create_node(const std::string &label)
     {
       node_ptr new_node(new node(label));
       return new_node;
     }

     // Return the label of this node.
     // Labels are unique across sibling nodes and must 63 characters or less.
     const std::string & get_label() const
     {
       return m_label;
     }

     node_ptr get_parent() const
     {
       return m_parent;
     }

     int num_children() const
     {
       return m_children.size();
     }

     void add_child(const std::string &name, node_ptr node)
     {
       m_children.insert(std::pair<std::string, node_ptr>(name, node));
     }

     node_ptr get_child_by_name(const std::string &name)
     {
       // First try find requested name
       children::iterator child;
       child = m_children.find(name);
       
       if(child == m_children.end())
         return node_ptr(NULL);

       return child->second;

     }

    private:
      // Construction of node classes should be private and deffered to
      // a public interface which can only return reference counted pointers
      // to node instances.
      node(const std::string &label):
        m_label(label),
        m_parent(NULL),
        m_children()
      { }

      node(const node &rhs);
      node& operator=(const node &rhs);

      // Private members
      const std::string m_label;
      node_ptr m_parent;

      typedef std::map<std::string, node_ptr> children;
      children m_children;
  };
  
}


#endif
