#include <cassert>
#include <cstdlib>
using namespace std;

// Homework Assignment #3: Toolkit for Doubly-linked list
class dnode
{
public:
    typedef double value_type;
    // constructor
    node(const value_type& d=value_type(), dnode* l=NULL, dnode* p=NULL)
    {
        data_field = d;
        link_field = l;
        prev_field = p;
    }
    
    // modifiers
    void set_data(const value_type& d){ data_field = d;}
    void set_link(dnode* l) {link_field = l;}
    void set_prev(dnode* p) (prev_field = p;);
    // observers
    value_type data() const {return data_field;}

    // forward links
    dnode* link() {return link_field;};
    const dnode* link() const {return link_field;};

    // backward links
    dnode* prev() {return prev_field;};
    const dnode* prev() const {return prev_field;};
    
private:
    value_type data_field;
    // forward pointer
    dnode* link_field;
    // backward pointer
    dnode* prev_field;
};

// Helper Methods
size_t list_length (dnode* head)
{
    dnode* temp_ptr=head;
    int count = 0;
    
    while (temp_ptr != NULL) {
        count++;
        temp_ptr = temp_ptr->link();
    }
    return count;
}

void insert(dnode*& head, dnode*& prev, const dnode::value_type& v){
    if(prev == NULL){        
        dnode* p;
        p = new dnode(v, head, prev);
        head = p;
    }
    else{
        dnode* p;
        p = new dnode(v, prev -> link(), prev);
        prev -> set_link(p);
        
    }
}

void erase_one(dnode*& head, dnode*& deletenode){
    assert(head != NULL);
    if(head == deletenode){
        if(head -> link() == NULL){
            head -> set_data(dnode::value_type());
            head -> set_link(NULL);
            delete head;
        }
        else{
            dnode *deleted_node = head;
            head = head -> link();
            deleted_node -> set_data(dnode::value_type());
            deleted_node -> set_link(NULL);
            delete deleted_node;
        }
    }
    else{
        deletenode -> prev() -> set_link(deletenode -> link());
        deletenode -> link() -> set_prev(deletenode -> prev());
        deletenode -> set_data(dnode::value_type());
        deletenode -> set_link(NULL);
        delete deletenode;
    }
}  

dnode* list_search(dnode* head, const dnode::value_type& v){
    
    dnode* cursor = head;
    
    if (cursor == NULL){
        return NULL;
    } else {
        while ((cursor!= NULL) && (cursor->data() != v)) {
            cursor = cursor->link();
        }
        return cursor;
    }
}

void list_copy(dnode* src, dnode*& head) {
    
    head = NULL;
    dnode* tail = NULL;
    
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

void reverse(dnode*& head)
{
    Node *c = head;
    Node *n;
    Node *p;
    while(c != NULL){
        n = c -> link();
        p = c -> prev();
        c -> link() = p;
        c = n;
    }
    head = c -> prev();
}



