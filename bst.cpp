#include "bits/stdc++.h"
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};
Node* insert(Node* &root, int x){
    if(root == NULL){
        root = new Node(x);
    }
    if(root->data > x){
        root->left = insert(root->left, x);
    }
    if(root->data < x){
        root->right = insert(root->right, x);
    }
    return root;
}
int maxval(Node* root){
    while (root->right != NULL){
        root = root->right;
    }
    return root->data;
}
int minval(Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root->data;
}
Node* deletebst(Node* &root, int d){
    if(root == NULL){
        return NULL;
    }
    if(root->data == d){
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if(root->left != NULL && root->right != NULL){
            int pred = maxval(root->left); // left se max and right se min
            int succ = minval(root->right);
            // root->data = pred;
            root->data = succ;
            // root->left = deletebst(root->left, pred);
            root->right = deletebst(root->right, succ);
            return root;
        }
    }

    else if(root->data > d){
        root->left = deletebst(root->left, d);
    }
    else {
        root->right = deletebst(root->right, d);
    }
    return root;
    
}
Node* makebst(Node* &root, int d){
    if(root == NULL){
        Node* new_node = new Node(d);
        return new_node;
    }
    if(root->data > d){
        root->left = makebst(root->left, d);
    }
    if(root->data < d){
        root->right = makebst(root->right, d);
    }
    return root;
}
void inp(Node* &root){
    int d;
    cin>>d;
    while(d != -1){
        root = makebst(root, d);
        cin>>d;
    }
}
void level(Node* root){
    if(root == NULL){
        cout<<"Empty\n";
        return;
    }
    queue<Node*> q;
    q.push(root);

    while(q.size()){
        int n = q.size();
        for(int i=0;i<n;i++){
            Node* curr = q.front();
            cout<<curr->data << " ";
            q.pop();
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        cout<<"\n";
    }
}
int main(){
    Node* root = NULL;
    cout<<"Enter data to insert in BST : ";
    inp(root);

    // level(root);
    root = insert(root, 29);
    root = insert(root, 35);
    root = insert(root, 302);
    level(root);
    cout<<"after deletion\n";
    root = deletebst(root, 46);
    level(root);
    
    return 0;

}