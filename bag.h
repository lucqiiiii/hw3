#ifndef BAG_H
#define BAG_H
#include node.h

using namespace std;

class bag
{
 public:
  typedef std::size_t size_type;
  typedef node::value_type value_type;

  // constructor
  bag();

  // copy constructor
  bag(const bag& src);

  // destructor
  ~bag();

  // modifiers
  void insert(const value_type& entry);
  bool erase_one(const value_type& target);
  size_type erase(const value_type& target);

  // observers
  size_type size() const {return num_nodes;};
  size_type count(const value_type&target) const;

 private:
  node* head;
  size_type num_nodes;

#endif
