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

vector<int> * getRootToNodePath(binaryTreeNode<int>* root , int data){
    if(root == NULL) return NULL;
    if(root->data == data){
        vector<int> * output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int> * leftOutput = getRootToNodePath(root->left,data);
    if(leftOutput != NULL){
        leftOutput->push_back(root->data);
        return leftOutput;
    }
    
    vector<int>* rightOutput = getRootToNodePath(root->right, data);
    if(rightOutput != NULL){
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    else {return NULL;}

}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
//just basic null and found base condition and left and right will give answer through recursion if found data return data THE END
int main(){
   binaryTreeNode<int>* root = takeInputLevelWise();
    // printTreeLevelWise(root);
    int data;
    cin>>data;
    vector<int>* output = getRootToNodePath(root,data);
    for (int i = 0; i < output->size(); i++)
    {
        cout<<output->at(i)<<" ";
    }
    
    delete output;

return 0;
}