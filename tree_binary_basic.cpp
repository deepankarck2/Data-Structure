#include<iostream>

using namespace std; 
struct BstNode{ //BST node
    int data; 
    BstNode* left;
    BstNode* right; 
};

BstNode* GetNewNode(int data){
    BstNode* newNode= new BstNode();
    newNode->data = data; 
    newNode->left = NULL; 
    newNode->right= NULL;
    
    return newNode; 
}

BstNode* Insert(BstNode* root, int data){
    if(root == NULL){
        root = GetNewNode(data); 
    }
    else{
        if(data > root->data){
            root->right = Insert(root->right, data); 
        }
        else if(data <= root->data){
            root->left = Insert(root->left, data); 
        }
    }
    return root; 
}
int main(){
    BstNode* root = NULL; //pointer to the root node 
    
    root = Insert(root, 15);
    root = Insert(root, 10); 
    root = Insert(root, 20); 

    return 0; 
}