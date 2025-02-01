#include<iostream>
#include<queue> 
#include "bits/stdc++.h"
using namespace std;
class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;

    }

};
node* buildTree(node* root){
    cout << "enter the data:"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    if(data == -1){
        return NULL;
    }
    cout<<"enter data for inserting in left"<<endl;
    root->left = buildTree(root->left);
    cout<<"enter data for inserting in right"<<endl;
    root->right = buildTree(root->right);
    return root;

}

void levelordertraversal(node* root) {
    if (root == NULL) return; // Handle empty tree
    
    queue<node*> q;
    q.push(root);
    q.push(NULL);  // Marker to indicate end of a level

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;  // New line after each level
            if (!q.empty()) {
                q.push(NULL);  // Add NULL for the next level
            }
        } else {
            cout << temp->data << " ";  // Print the node's data
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}
void heightt(struct node* node){
    if(node==NULL){
        return 0;
    }
    int left = heightt(node -> left);
    int right = heightt(node->right);
    int ans = max(left,right)+1;
    return ans;
 
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    levelordertraversal(root);



    return 0;
}