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

int numNodes(TreeNode<int>* root){
	int ans=1;
	for (int i = 0; i < root->children.size(); i++)
	{
		ans+=numNodes(root->children[i]);
	}
	return ans;
}

int Sum(TreeNode<int>* root){
    int total=root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        total+=Sum(root->children[i]);
    }
    return total;
}

int maximum(TreeNode<int>* root){

    int temp = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        temp=max(temp,maximum(root->children[i]));
    }
    return temp;
}

int heightOfTree(TreeNode<int>* root){  

    int height=1;
    if(root->children.size() == 0){
        return height;
    }

    int ar[root->children.size()];
    for (int i = 0; i <root->children.size() ; i++)
    {
        ar[i] = heightOfTree(root->children[i]);
    }
    sort(ar,ar+(root->children.size()));
    height+=ar[(root->children.size())-1];
    return height;
}


int main(){
	
	TreeNode<int>* root = takeInputLevelWise();
	printTreeLevelWise(root);
	cout<< "Total number of nodes: "<< numNodes(root) << endl;
	cout<< "Total sum of all nodes: " << Sum(root) << endl;
    cout<< "Maximum data: " << maximum(root) << endl;
    cout<< "Height: "<< heightOfTree(root) << endl;

}
