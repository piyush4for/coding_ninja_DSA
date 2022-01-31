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

void searchk1k2(binaryTreeNode<int>* root, int k1,int k2){
    if(root == NULL) return ;
    if(root->data >= k1 & root->data<=k2) cout<<root->data<<" ";
    if(root->data>k1) searchk1k2(root->left,k1,k2);
    if(root->data<k2) searchk1k2(root->right,k1,k2);
}

//8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1 6 10
int main(){
   binaryTreeNode<int>* root = takeInputLevelWise();
    printTreeLevelWise(root);
    int k1,k2;
    cin>>k1>>k2;
    searchk1k2(root,k1,k2);
    delete root;
return 0;
}