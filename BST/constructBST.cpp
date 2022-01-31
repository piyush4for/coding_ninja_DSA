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

binaryTreeNode<int>* MakeBST(int ar[],int si, int ei){
    if(si>ei) return NULL;
    int mid = (si+ei)/2;
    binaryTreeNode<int>* root = new binaryTreeNode<int>(ar[mid]);
    root->left = MakeBST(ar,si,mid-1);
    root->right = MakeBST(ar,mid+1,ei);
    
    return root;
}

void PreOrder(binaryTreeNode<int>* root){
    if(root == NULL) return ;
    cout<<root->data;
    PreOrder(root->left);
    PreOrder(root->right);
}
//7 1 2 3 4 5 6 7
int main(){
   int count;
   cin>>count;
   int ar[count];
   for (int i = 0; i < count; i++)
   {
       cin>>ar[i];
   }
   binaryTreeNode<int>* root = MakeBST(ar,0,count-1);
    // printTreeLevelWise(root);
    PreOrder(root);
    delete root;

return 0;
}