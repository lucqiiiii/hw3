#include <cassert>
#include <cstdlib>
using namespace std;

// Homework Assignment #3: Toolkit for Doubly-linked list
class dnode
{
public:
    typedef double value_type;
    // constructor
    node(const value_type& d=value_type(), node* l=NULL, node* p=NULL)
    {
        data_field = d;
        link_field = l;
        prev_field = p;
    }
    
    // modifiers
    void set_data(const value_type& d){ data_field = d;}
    void set_link(node* l) {link_field = l;}
    void set_prev(node* p) (prev_field = p;);
    // observers
    value_type data() const {return data_field;}

    // forward links
    node* link() {return link_field;};
    const node* link() const {return link_field;};

    // backward links
    node* prev() {return prev_field;};
    const node* prev() const {return prev_field;};
    
private:
    value_type data_field;
    // forward pointer
    node* link_field;
    // backward pointer
    node* prev_field;
};

// Helper Methods
size_t list_length (node* head)
{
    node* temp_ptr=head;
    int count = 0;
    
    while (temp_ptr != NULL) {
        count++;
        temp_ptr = temp_ptr->link();
    }
    return count;
}

void list_head_insert(node*& head, const node::value_type& v) {
    
    node* p;
    p = new node(v, head);
    head = p;
}

void list_insert(node* prev, const node::value_type& v){
    
    assert(prev != NULL);
    node* q;
    q = new node(v, prev->link());
    prev->set_link(q);
    prev=NULL;
    
}

node* list_search(node* head, const node::value_type& v){
    
    node* cursor = head;
    
    if (cursor == NULL){
        return NULL;
    } else {
        while ((cursor!= NULL) && (cursor->data() != v)) {
            cursor = cursor->link();
        }
        return cursor;
    }
}

void list_copy(node* src, node*& head) {
    
    head = NULL;
    node* tail = NULL;
    
    if (src == NULL){ // Empty source list
        return;
    }
    
    // inserting the first node in the copy
    list_head_insert(head, src->data());
    tail = head;
    
    // inserting the rest of the nodes from src to the copy
    src = src->link();
    while (src != NULL) {
        list_insert(tail, src->data());
        tail = tail->link();
        src = src->link();
    }
}

// START OF LECTURE #10: October 29, 2018

void list_head_remove(node*& head)
{

  
}

vooid list_remove(node* prev_ptr)
{




}

void list_clear(node*& head) 
{

   

}



