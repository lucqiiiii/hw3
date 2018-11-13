//Qi Guo Keely Yeh

#include <cassert>
#include <cstdlib>
using namespace std;

// Homework Assignment #3: Toolkit for Doubly-linked list
class dnode
{
public:
    typedef double value_type;
    // constructor
    dnode(const value_type& d=value_type(), dnode* l=NULL, dnode* p=NULL)
    {
        data_field = d;
        link_field = l;
        prev_field = p;
    }
    
    // modifiers
    void set_data(const value_type& d){ data_field = d;}
    void set_link(dnode* l) {link_field = l;}
    void set_prev(dnode* p) {prev_field = p;};
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
        p -> link() -> set_prev(p);
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

void reverse(dnode*& head)
{
    dnode *c = head;
    dnode *n;
    dnode *p;
    while(c != NULL){
        n = c -> link();
        p = c -> prev();
        c -> set_link(p);
        c = n;
    }
    head = c -> prev();
}



