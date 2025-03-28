#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    char data;
    Node* child[26];
    bool isTerminal;
    Node(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    public:
    Node* root;
    Trie(){
        root = new Node('\0');
    }
    void util1(Node* root, string w){
        if(w.size()==0){
            root->isTerminal = true;
            return;
        }
        int ind = w[0]-'A';
        Node* new_child;
        if(root->child[ind] != NULL){
            new_child = root->child[ind];
        }
        else{
            new_child = new Node(w[0]);
            root->child[ind] = new_child;
        }
        util1(new_child, w.substr(1));
    }

    bool util2(Node* root, string w){
        if(w.size()==0){
            return root->isTerminal;
        }
        int ind = w[0]-'A';
        Node* new_child;
        if(root->child[ind] != NULL){
            new_child = root->child[ind];
        }
        else{
            return false;
        }

        return util2(new_child, w.substr(1));
    }

    void util3(Node* root, string w){
        if(w.size()==0){
            root->isTerminal = false;
            return;
        }
        Node* new_child;
        int ind = w[0]-'A';
        if(root->child[ind] != NULL){
            new_child = root->child[ind];
        }
        else{
            cout<<"Word is already absent\n";
            return;
        }
        util3(new_child, w.substr(1));
    }

    void insertword(string w){
        util1(root, w);
    }
    bool searchword(string w){
        return util2(root, w);
    }
    void removeword(string w){
        return util3(root, w);
    }

};
int main(){
    Trie *t = new Trie;

    t->insertword("TIME");
    t->insertword("TYRIN");
    t->insertword("DO");
    t->insertword("NISH");
    cout<<"Present or not "<<t->searchword("NISH")<<"\n";
    cout<<"Remove "<<t->removeword("NISH")<<"\n";
    cout<<"Present or not "<<t->searchword("NISH")<<"\n";

}