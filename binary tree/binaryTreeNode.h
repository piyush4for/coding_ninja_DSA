template <typename T>

class binaryTreeNode{
    public:
    int data;
    binaryTreeNode* left;
    binaryTreeNode* right;

 binaryTreeNode(T data){
     this->data = data;
     left=NULL;
     right=NULL;
 }

 ~binaryTreeNode(){
     delete left;
     delete right;
 }

};