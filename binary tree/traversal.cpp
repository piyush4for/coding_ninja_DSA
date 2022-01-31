#include <iostream>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include<algorithm>
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

void inorder(binaryTreeNode<int>* root){
    if(root == NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(binaryTreeNode<int>* root){
    if(root == NULL) return ;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
//1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
//4 type of traversal in binary tree while 
/*
    1.Level Order(horizontally)
    2.PreOrder(node->left->right)
    3.PostOrder(left->right->node)   
    4.Inorder(Left->node->right)
*/
int main(){
   binaryTreeNode<int>* root = takeInputLevelWise();
    // inorder(root);
    preorder(root);
    
    delete root;
return 0;
}