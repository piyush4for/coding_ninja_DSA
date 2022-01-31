//this will be use as BST.insert() . this is latest
#include "binaryTreeNode.h"
#include<iostream>
using namespace std;
class BST{
    public:
    binaryTreeNode<int>* root;

    BST(){
        root = NULL;
    }

    ~BST(){
        delete root;
    }
    void insert(int data){
        this->root = insert(data,this->root);
    }

    void deleteData(int data){
        this->root = deleteData(data,root);
    }
    
    bool hasData(int data){
        return hasData(data,root);
    }

    void printTree(){
        printTree(root);
    }

    private:
        binaryTreeNode<int>* insert(int data, binaryTreeNode<int>* node){
            if(node == NULL) {
                binaryTreeNode<int>* newNode = new binaryTreeNode<int>(data);
                return newNode;
            }
            if(data < node->data){
                node->left = insert(data, node->left);
            }
            else{
                node->right = insert(data,node->right);
            }
            return node;
        }

        binaryTreeNode<int>* deleteData(int data,binaryTreeNode<int>* node){
            if(node == NULL) return NULL;
            if(data > node->data) {
                node->right = deleteData(data, node->right);
                return node;
            } 
            else if(data < node->data) {
                node->left = deleteData(data, node->left);
                return node;
            } 
            else{
                if(node->left == NULL && node->right == NULL) {
                    delete node;
                    return NULL;
                } 
                else if(node->left == NULL) {
                    binaryTreeNode<int>* temp = node->right;
                    node->right = NULL;
                    delete node;
                    return temp;
                } 
                else if (node->right == NULL) {
                    binaryTreeNode<int>* temp = node->left;
                    node->left = NULL;
                    delete node;
                    return temp; 
                } 
                else {
                    binaryTreeNode<int>* minNode = node->right;
                    while (minNode->left != NULL) {
                        minNode = minNode->left;
                    }
                    int rightMin = minNode->data;
                    node->data = rightMin;
                    node->right = deleteData(rightMin, node->right);
                    return node;
                }
            }
	}
        
        
        bool hasData(int data, binaryTreeNode<int>* node){
            if(node == NULL) return false;
            if(node->data == data) return true;
            else if(data < node->data) return hasData(data,node->left);
            else if(data > node->data) return hasData(data,node->right);
        }

         void printTree(binaryTreeNode<int>* root){
            if(root == NULL){
                return;
            }
            cout<<root->data<<":";
            if(root->left != NULL){
                cout<<"L"<< root->left->data; 
            }

            if(root->right != NULL){
                cout<<"R"<< root->right->data; 
            }
            cout<<endl;
            printTree(root->left);
            printTree(root->right);

        }
       
};