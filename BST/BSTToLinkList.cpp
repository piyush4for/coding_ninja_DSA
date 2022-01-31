#include <iostream>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include<algorithm>
#include<limits.h>
#include<queue>
#include "binaryTreeNode.h"
#include "../LinkedList/Node.cpp"
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

class Pair{
    public:
    Node* head;
    Node* tail;
};

Pair BST(binaryTreeNode<int> * root){
    if(root==NULL)
    {
        Pair ans ;
        ans.head=NULL;
        ans.tail=NULL;
        return ans;

    }
    
	Node *node= new Node(root->data);
    
    Pair leftans=BST(root->left);
    Pair rightans=BST(root->right);
    
    
    Pair ans;
    
    if(leftans.head==NULL && rightans.head==NULL)
    {
        
        ans.head=node;
        ans.tail=node;
       
    }
    
   else if(!leftans.head && rightans.head  )
   		 { ans.head=node;
           node->next=rightans.head;
   		     
        	ans.tail=rightans.tail;
  		  }
  else if(leftans.head && rightans.head==NULL)
  		  { ans.head=leftans.head;
      			leftans.tail->next=node;
  		        ans.tail=node;
               
  		  }
    else
    {
        ans.head=leftans.head;
        leftans.tail->next=node;
        node->next=rightans.head;
        ans.tail=rightans.tail;
    }
    
     return ans;
   
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
//seperated tree into 3 parts leftside root right side . a ans node which is connected in a way to make ll
int main(){
   binaryTreeNode<int>* root = takeInputLevelWise();
    // printTreeLevelWise(root);
    Node* ans = BST(root).head;
    print(ans);
    delete root;

return 0;
}