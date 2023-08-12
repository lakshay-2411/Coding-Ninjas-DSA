#include "BSTNode.h"

class BST{
    BinaryTreeNode<int>* root;

    public:

    BST(){
        root = NULL;
    }
    ~BST(){
        delete root;
    }
    
    private:

    bool hasData(int data,BinaryTreeNode<int>* node){
        if(node == NULL){
            return false;
        }
        if(node->data == data){
            return true;
        }else if(data < node->data){
            return hasData(data,node->left);
        }else{
            return hasData(data,node->right);
        }
    }

    BinaryTreeNode<int>* insert(int data,BinaryTreeNode<int>* node){
        if(node == NULL){
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if(data <= node->data){
            node->left = insert(data,node->left);
        }else{
            node->right = insert(data,node->right);
        }
        return node;
    }

    void printTree(BinaryTreeNode<int>* node){
        if(root == NULL){
            return;
        }
        cout << root->data << ":";
        if(root->left!=NULL){
            cout << "L:" << root->left->data << ",";
        }
        if(root->right!=NULL){
            cout << "R:" << root->right->data;
        }
        cout << endl;
        printTree(root->left);
        printTree(root->right);
    }

    BinaryTreeNode<int>* deleteData(int data,BinaryTreeNode<int>* node){
        if(root == NULL){
            return NULL;
        }
        if(data < node->data){
            node->left = deleteData(data,node->left);
            return node;
        }else if(data > node->data){
            node->right = deleteData(data,root->right);
            return node;
        }else{
            if(node->left==NULL&&node->right==NULL){
                delete node;
                return NULL;
            }else if(node->left==NULL){
                BinaryTreeNode<int>* temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }else if(node->right==NULL){
                BinaryTreeNode<int>* temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }else{
                BinaryTreeNode<int>* maxNode = node->left;
                while(maxNode->right!=NULL){
                    maxNode = maxNode->right;
                }
                int leftMax = maxNode->data;
                node->data = leftMax;
                node->left = deleteData(leftMax,node->left);
                return node;
            }
        }
    }

    public:
    void deleteData(int data){
        root = deleteData(data,root);
    }
    void insert(int data){
        this->root = insert(data,root);
    }
    void print(){
        printTree(root);
    }
    bool hasData(int data){
        return hasData(data,root);
    }
};