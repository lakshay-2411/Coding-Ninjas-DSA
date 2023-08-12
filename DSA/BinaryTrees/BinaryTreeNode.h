#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};

vector<int> levelOrder(BinaryTreeNode<int>* root){
    vector<int> ans;
    if(root == NULL) return ans;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(q.size() != 0){
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        ans.push_back(front->data);
        if(front->left != NULL) q.push(front->left);
        if(front->right != NULL) q.push(front->right);
    }
    return ans;
}

void printlevelWise(BinaryTreeNode<int>* root){
    if(root == NULL) return;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            BinaryTreeNode<int>* front = q.front();
            q.pop();
            cout << front->data << " ";
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
        cout << endl;
    }
}