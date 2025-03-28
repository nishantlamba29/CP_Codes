#include <bits/stdc++.h>
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

Node* make_tree(Node* root){
    if(root == NULL) 
    cout<<"Enter data of the root : \n";
    int data;
    cin>>data;
    root = new Node(data);
    if(data == -1){
        return NULL;
    }
    cout<<"Enter value of left of : "<<data<<"\n";
    root->left = make_tree(root->left);
    cout<<"Enter value of right of "<<data<<"\n";
    root->right = make_tree(root->right);
    
}

void bfs(Node* root){
    queue<Node*> q;
    q.push(root);
    while(q.size()){
        Node* curr = q.front();
        q.pop();
        if(curr != NULL) cout<<curr->data<<" ";
        if(curr->left != NULL)
        q.push(curr->left);
        if(curr->right != NULL)
        q.push(curr->right);
    }
}
void preorder(Node* root){
    if(root == NULL) return;
    stack<Node*> st;
    while(root != NULL || st.size()){
        while(root != NULL){
            cout<<root->data<<" ";
            if(root->right)
            st.push(root->right);
            root = root->left;
        }
        if(st.size()){
            root = st.top();
            st.pop();
        }
    }
}
void inorder(Node* root){
    if(root == NULL) return;
    stack<Node*> st;
    while(root != NULL || st.size()){
        while(root != NULL){
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        cout<<root->data<<" ";
        root = root->right;
    }
}
void postorder(Node* root) {
    if (root == NULL) return;
    
    stack<Node*> st1, st2;
    st1.push(root);
    
    while (!st1.empty()) {
        Node* node = st1.top();
        st1.pop();
        st2.push(node);
        
        if (node->left)
            st1.push(node->left);
        if (node->right)
            st1.push(node->right);
    }
    
    // Print the nodes from the second stack
    while (!st2.empty()) {
        Node* node = st2.top();
        st2.pop();
        cout << node->data << " ";
    }
}

int main() {
	// your code goes here
	Node* root = new Node(1);
	// make_tree(NULL);
    root->left = new Node(5);
    root->right = new Node(7);
    root->left ->left = new Node(11);
    root->left->right = new Node(13);
    root->right->left = new Node(15);
    root->right->right = new Node(17);
    // bfs(root);
    postorder(root);cout<<"\n";
    inorder(root);cout<<"\n";
    preorder(root);cout<<"\n";

}
