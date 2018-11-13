//Qi Guo Kelly Yeh

#ifndef NODE_H
#define NODE_H

#include <cassert>
#include <cstdlib>
using namespace std;

class node
{
public:
    typedef double value_type;
    // constructor
    node(const value_type& d=value_type(), node* l=NULL)
    {
        data_field = d;
        link_field = l;
    }
    
    // modifiers
    void set_data(const value_type& d){ data_field = d;}
    void set_link(node* l) {link_field = l;}
    
    // observers
    value_type data() const {return data_field;}
    node* link() {return link_field;};
    const node* link() const {return link_field;};
    
private:
    value_type data_field;
    // pointer
    node* link_field;
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
    node* deleted_node = head;
    head = head->link();
    
    deleted_node->set_data(node::value_type());
    deleted_node->set_link(NULL);
    delete deleted_node;
}

void list_remove(node* prev_ptr)
{
    node* deleted_node = prev_ptr->link();
    
    // set the link to skip over the node
    // to be removed
    prev_ptr->set_link(deleted_node->link());
    
    // clean up the node
    deleted_node->set_data(node::value_type());
    deleted_node->set_link(NULL);
    // deallocate the node back to the memory
    delete deleted_node;
}

void list_clear(node*& head) 
{

    while (head!=NULL) {
        list_head_remove(head);
    }

}

void reverse(node*& head){
    node *p = NULL;
    node *c = head;
    node *n;
    while(c != NULL){
        n = c -> link();
        c -> set_link(p);
        p = c;
        c = n;
    }
    head = p;
}


#endif
