#include "bits/stdc++.h"
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};
void insert(Node* &tail, int ele, int val){
    if(tail == NULL){
        Node* new_node = new Node(val);
        tail = new_node;  // do it 
        new_node->next = new_node;
    }
    else{
        Node* curr = tail;
        while(curr->data != ele){
            curr = curr->next;
        }
        Node* new_node = new Node(val);
        new_node->next = curr->next;
        curr->next = new_node;
    }
}
void dltnode(Node* &tail, int ele){
    if(tail == NULL){
        cout<<"Empty list\n";
        return;
    }
    if(tail->next == tail){
        tail = NULL;
        return;
    }
    Node* prev = tail;
    Node* curr = prev->next;
    while(curr->data != ele){
        prev = curr;
        curr = curr->next;
    }
    if(curr == tail)
    tail = prev; // in case delete the tail node
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}
void print(Node* tail){
    if(tail == NULL){
        cout<<"Empty List\n";
        return;
    }
    Node* temp = tail;
    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    }while(tail != temp);
    cout<<"\n";
}
int main(){

    Node* tail = NULL;
    insert(tail, 5, 3);
    print(tail);
    insert(tail, 3, 4);
    print(tail);
    // insert(tail, 4, 5);
    // print(tail);
    // insert(tail, 5, 6);
    // print(tail);
    // insert(tail, 4, 9);
    // print(tail);
    dltnode(tail, 4); print(tail);


    return 0;
}