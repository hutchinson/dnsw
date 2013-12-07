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
  typedef std::weak_ptr<node> weak_node_ptr;

  // Classes
  class node
  {
    public:
     
     // Creates a new instance of a node with the label provided and returns
     // it as a reference counted resource with ownership of the object
     // transferred to the caller
     static node_ptr create_node(const std::string &label)
     {
       node_ptr new_node(new node(label));
       return new_node;
     }

     static void add_child(node_ptr parent, node_ptr child)
     {
       // Add the child node to the parent (the parent assumes ownernship)
       parent->add_child(child->get_label(), child);
       child->set_parent(parent);
     }

     // Return the label of this node.
     // Labels are unique across sibling nodes and must 63 characters or less.
     const std::string & get_label() const
     {
       return m_label;
     }

     // Return a weak reference to this node's parent. The root of the tree's
     // parent is NULL.
     weak_node_ptr get_parent() const
     {
       return m_parent;
     }

     // Set this node's parent to the specified node
     void set_parent(weak_node_ptr parent)
     {
        m_parent = parent;
     }

     int num_children() const
     {
       return m_children.size();
     }

     // Add the specified node as a child of this node.
     void add_child(const std::string &name, node_ptr child)
     {
       m_children.insert(std::pair<std::string, node_ptr>(name, child));
     }

     // Returns a weak reference to the child specified by the name.
     weak_node_ptr get_child_by_name(const std::string &name)
     {
       // First try find requested name
       children::iterator child;
       child = m_children.find(name);
       
       if(child == m_children.end())
         return weak_node_ptr();

       return weak_node_ptr(child->second);
     }

     ~node()
     {
       std::cout << "~node '" << m_label << "'" << std::endl;
     }

    private:
      // Construction of node classes should be private and deffered to
      // a public interface which can only return reference counted pointers
      // to node instances.
      node(const std::string &label):
        m_label(label),
        m_parent(),
        m_children()
      { }

      node(const node &rhs);
      node& operator=(const node &rhs);


      // Private members
      const std::string m_label;
      weak_node_ptr m_parent;

      typedef std::map<std::string, node_ptr> children;
      children m_children;
  };
}


#endif
