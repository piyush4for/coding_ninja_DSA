#include <iostream>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include<algorithm>
#include<limits.h>
#include<queue>
#include "binaryTreeNode.h"
using namespace std;

void printTreeLevelWise(binaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    queue<binaryTreeNode<int>*> pendingNode;
    pendingNode.push(root);

    while(pendingNode.size() != 0){
        binaryTreeNode<int>* front = pendingNode.front();
        pendingNode.pop();
        cout<<front->data<<":";

        if(front->left != NULL){
            cout<<"L"<< front->left->data; 
            pendingNode.push(front->left);
        }
        if(front->right != NULL){
            cout<<"R"<< front->right->data; 
            pendingNode.push(front->right);
        }
        cout<<endl;
    }
}

binaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root data"<< endl;
    cin>>rootData;
    if(rootData == -1) return NULL;

    binaryTreeNode<int>* root = new binaryTreeNode<int>(rootData);

    queue<binaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        binaryTreeNode<int>* front = pendingNodes.front();
        cout<<"Enter left child of "<<front->data<<endl;
        pendingNodes.pop();
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData != -1){
            binaryTreeNode<int>* child = new binaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        
        cout<<"Enter right child of "<<front->data<<endl;
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData != -1){
            binaryTreeNode<int>* child = new binaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

int maximum(binaryTreeNode<int>* root){
    if(root == NULL) return INT_MAX;
    return max(root->data , max(maximum(root->right),maximum(root->left)));
}
int minimum(binaryTreeNode<int>* root){
    if(root == NULL) return INT_MAX;
    return min(root->data , min(minimum(root->right),minimum(root->left)));
}

bool isBST(binaryTreeNode<int>* root){

    if(root == NULL) return true;
    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);
    bool output = (root->data>leftMax) && (root->data<=rightMin) && isBST(root->left) && isBST(root->right);

    return output;
}

//8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1 2
int main(){
   binaryTreeNode<int>* root = takeInputLevelWise();
    printTreeLevelWise(root);
    cout<<"is it bst: "<<isBST(root);
    delete root;
return 0;
}