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

int numNode(binaryTreeNode<int>* root){
    if(root == NULL) return 0;

    return 1+numNode(root->left) + numNode(root->right);
}

bool isNodePresent(binaryTreeNode<int>* root, int element){
    bool ans=false;
    if(root->data == element)  ans=true;
    
    if(root->left){
        bool leftSide = isNodePresent(root->left,element);
        if(leftSide) ans = leftSide;
    }
    if(root->right){
        bool rightSide = isNodePresent(root->right,element);
        if(rightSide) ans = rightSide;
    }
   return ans;
}

int heightTree(binaryTreeNode<int>* root){
    int height=1;
    if(root->left == NULL & root->right == NULL) return height;
    int ar[2];
    ar[0]= heightTree(root->left);
    ar[1]=heightTree(root->right);
    height+=max(ar[0],ar[1]);

    return height;
}

//1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
int main(){
   binaryTreeNode<int>* root = takeInputLevelWise();
    printTreeLevelWise(root);
    cout<<"number of node :"<<numNode(root)<<endl;
    int isPresent=0;
    cout<<"enter element to check is present or not:";
    cin>>isPresent;
    cout<<isNodePresent(root,isPresent)<<endl;
    cout<<"height of tree: "<<heightTree(root)<<endl; 
    delete root;
return 0;
}