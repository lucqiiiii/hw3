//Qi Guo Kelly Yeh
#include "bag.h"
using namespace std;


bag::bag(){
    head = NULL;
    num_nodes = 0;
}

bag::bag(const bag& src){
    list_copy(src.head,head);
    num_nodes = src.num_nodes;
}

bag::~bag(){
    list_clear(head);
    num_nodes = 0;
}

void bag::insert(const value_type& entry){
    list_head_insert(head,entry);
    num_nodes++;
}

bool bag::erase_one(const value_type& target){
    node *target_node;
    target_node = list_search(head,target);
    if(target_node == NULL){
        return false;
    }
    target_node -> set_data(head -> data());
    list_head_remove(head);
    num_nodes--;
    return true;
}

bag::size_type bag::erase(const value_type& target){
    size_type num = 0;
    node *target_node;
    target_node = list_search(head,target);
    while(target_node != NULL){
        target_node -> set_data(head -> data());
        target_node = target_node -> link();
        target_node = list_search(target_node, target);
        list_head_remove(head);
        num_nodes--;
        num++;
    }
    return num;
}

