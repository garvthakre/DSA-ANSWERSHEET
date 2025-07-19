#include<iostream>
#include<vector>
#include "bits/stdc++.h"
using namespace std;


class Node {
    public:
    int data;
    Node* right ;
    Node* left;
    Node(int val){
        data  = val;
        left = right = NULL;

    }
};
static int idex = -1;
Node* BuildTree(vector<int> preorder){
    idex++;
     if (idex >= preorder.size() || preorder[idex] == -1) {   
        return NULL;
    }
 
Node* root = new Node(preorder[idex]);
root->left = BuildTree(preorder);
root->right = BuildTree(preorder);
return root;
}
void preordertt(Node* root){
    if(root == NULL){
        return ;

    }

    cout<<root->data<<endl;
    preordertt(root->left);
     preordertt(root->right);   
}
void inorder(Node* root){
    if (root ==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}
void postorder(Node* root){
    if(root ==NULL){
        return ;

    }
    postorder(root->left);
    postorder(root->right);
    cout<< root->data<<endl;
}
int main(){
   vector<int> preorder = {1, 2, 3, -1, -1, -1, 4, -1, -1};

    idex = -1; 
    Node* root = BuildTree(preorder);
   preordertt(root);  // Output: 1 2 3 4
    cout << endl;
return 0;
}