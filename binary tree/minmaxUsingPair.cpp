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


pair<int,int> minmax(binaryTreeNode<int>* root){
    if(root->left == NULL && root->right == NULL){
        pair<int,int> p;
        p.first = p.second = root->data;
        return p;
    }
    pair<int,int> p;
    p.first = p.second = root->data;

    if(root->left){
        pair<int,int> smalloutput = minmax(root->left);
        p.first = min(p.first,smalloutput.first);
        p.second = max(p.second,smalloutput.second);
    }
    if(root->right){
        pair<int,int> smalloutput = minmax(root->right);
        p.first = min(p.first,smalloutput.first);
        p.second = max(p.second,smalloutput.second);
    }
    return p;
}

//1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
int main(){
   binaryTreeNode<int>* root = takeInputLevelWise();
    printTreeLevelWise(root);
    // cout<<diameter(root);
    pair<int, int> p = minmax(root);
    cout<<"minimum: "<<p.first<<endl;
    cout<<"maximum: "<<p.second<<endl;
    delete root;
return 0;
}