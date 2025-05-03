#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"memory is freed with data "<<value<<"\n";
    }
};
void inserthead(Node* &head, int val){
    Node* new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}
void inserttail(Node* &tail, int val){
    Node* new_node = new Node(val);
    tail->next = new_node;
    tail = new_node;
}
void insertpos(Node* &head, int val, int pos){
    int cnt = 1;
    if(pos==1){
        inserthead(head, val);
        return;
    }
    Node* temp = head;
    while(cnt < pos-1){
        temp = temp->next;
        cnt++;
    }
    if(temp->next == NULL){
        inserttail(temp,val);
        return;
    }
    Node* new_node = new Node(val);
    new_node->next = temp->next;
    temp->next = new_node;

}
void deletenode(Node* &head,Node* &tail, int pos){
    Node* temp = head;
    int cnt= 1;
    if(pos==1){
        Node* dltnode = head;
        head = head->next;
        dltnode->next = NULL; // imp
        delete dltnode;
        return;
    }
    while(cnt < pos-1){
        temp = temp->next;
        cnt++;
    }
    if(temp->next->next == NULL){
        tail=temp;
    }
    Node* dltnode = temp->next;
    temp->next = dltnode->next;
    dltnode->next = NULL; // imp
    delete dltnode;
}
void dlt_node_val(Node* &head,Node* &tail, int val){
    Node* temp = head;
    int pos = 1;
    while(temp->data != val){
        temp = temp->next;
        pos++;
        if(temp->next == NULL){
            cout<<"Already not present\n";
            return;
        }
    }
    
    deletenode(head,tail, pos);
}
void print(Node* &head){
    for(Node* temp = head;temp!= NULL;temp = temp->next){
        cout<<temp->data<<" ";
    }
    cout<<"\n";
}
void display(Node* &head, Node* &tail){
    cout<<"head "<<head->data<<" tail "<<tail->data<<"\n";
}
int main(){

    Node* head = new Node(1);
    Node* tail = head;
    // print(head);
    inserthead(head,2);
    // print(head);
    inserthead(head, 3);
    // print(head);
    inserttail(tail, 4);
    // print(head);
    inserttail(tail, 5);
    // print(head);
    insertpos(head, 7, 3); print(head);
    display(head, tail);
    deletenode(head,tail, 6);print(head);
    display(head, tail);
    // dlt_node_val(head, 3); print(head);

    return 0;
}