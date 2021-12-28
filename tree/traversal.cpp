#include <iostream>
#include <queue>
#include<algorithm>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* takeInputLevelWise(){
	int rootData;
	cout<<"Enter root data" <<endl;
	cin>>rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	queue<TreeNode<int>*> pendingNodes;

	pendingNodes.push(root);
	while(pendingNodes.size() != 0){
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout<<"Enter num of children of " << front->data <<endl;
		int numChild;
		cin>>numChild;
		for (int i = 0; i < numChild; i++)
		{
			int childData;
			cout<< "Enter "<< i << "th child of " << front->data <<endl;
			cin>>childData;
			TreeNode<int>* child = new TreeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
		
	}
	return root;
}

void printTreeLevelWise(TreeNode<int>* root){
	if (root == NULL){
		return;
	}
	queue<TreeNode<int>*> pendingNode;
	pendingNode.push(root);
	while(pendingNode.size()!=0){
		TreeNode<int>* front = pendingNode.front();
		pendingNode.pop(); 
		cout<<front->data<<":";
		for(int i = 0; i <front->children.size() ; i++){ 
			cout<< front->children[i]->data << ",";
			
			pendingNode.push(front->children[i]);
		}
		cout<<endl;
	}
}

void preorder(TreeNode<int>* root){
    cout<<root->data<<" ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preorder(root->children[i]);
    }  
}

void postorder(TreeNode<int>* root){

    for (int i = 0; i < root->children.size(); i++)
    {
        postorder(root->children[i]);
    }  
    cout<<root->data<<" ";
}

void deleteTree(TreeNode<int>* root){
	for (int i = 0; i < root->children.size(); i++)
	{
		deleteTree(root->children[i]);
	}
	delete root;
}

int main(){
	//1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0 
	TreeNode<int>* root = takeInputLevelWise();
	// printTreeLevelWise(root);
    preorder(root);
    postorder(root);
	
	deleteTree(root);

}
