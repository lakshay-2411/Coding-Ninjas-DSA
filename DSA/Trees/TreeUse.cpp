#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode.h"
using namespace std;

//-------------------------------TAKING_INPUT_LEVEL_WISE------------------------------------------
TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter number of children of " << front->data << endl;
        int numChild;
        cin >> numChild;
        for(int i=0;i<numChild;i++){
            int childData;
            cout << "Enter " << i << "th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

//--------------------------------------TAKING_INPUT-----------------------------------------------
TreeNode<int>* takeInput(){
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    int n;
    cout << "Enter number of children of " << rootData << endl;
    cin >> n;
    for(int i=0;i<n;i++){
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

//------------------------------------PRINTING_TREE------------------------------------------------
void printTree(TreeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout << root->data << ":";
    for(int i=0;i<root->children.size();i++){
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}

//--------------------------------PRINTING_TREE_LEVEL_WISE------------------------------------------
void printTreeLevelWise(TreeNode<int>* root){
    if(root == NULL){
        return;
    }
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data <<":";
        for(int i=0;i<front->children.size();i++){
            cout << front->children[i]->data << ",";
        }
        cout << endl;
        for(int i=0;i<front->children.size();i++){
            pendingNodes.push(front->children[i]);
        }
    }
}


//------------------------------------NUMBER_OF_NODES-----------------------------------------------
int numNode(TreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    int ans = 1;
    for(int i=0;i<root->children.size();i++){
        ans += numNode(root->children[i]);
    }
    return ans;
}

//------------------------------------SUM_TOTAL_OF_NODES--------------------------------------------
int sumNode(TreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    int sum = root->data;
    for(int i=0;i<root->children.size();i++){
        sum += sumNode(root->children[i]);
    }
    return sum;
}

//---------------------------------------LARGEST_NODE-----------------------------------------------
int largestNode(TreeNode<int>* root){
    if(root == NULL){
        return -1;
    }
    int ans = root->data;
    for(int i=0;i<root->children.size();i++){
        int largestChild = largestNode(root->children[i]);
        if(largestChild > ans){
            ans = largestChild;
        }
    }
    return ans;
}

//--------------------------------------HEIGHT_OF_TREE----------------------------------------------
int findHeight(TreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    int h = 0;
    for(int i=0;i<root->children.size();i++){
        int childH = findHeight(root->children[i]);
        if(childH > h){
            h = childH;
        }
    }
    return h+1;
}

//-------------------------------------PRINT_AT_LEVEL_K---------------------------------------------
void printAtLevelK(TreeNode<int>* root,int k){
    if(root == NULL){
        return;
    }
    if(k == 0){
        cout << root->data << endl;
    }
    for(int i=0;i<root->children.size();i++){
        printAtLevelK(root->children[i],k-1);
    }
}

//---------------------------------------PREORDER_TRAVERSAL-----------------------------------------
void preorder(TreeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    for(int i=0;i<root->children.size();i++){
        preorder(root->children[i]);
    }
}

//--------------------------------------POSTORDER_TRAVERSAL-----------------------------------------
void postorder(TreeNode<int>* root){
    if(root == NULL){
        return;
    }
    for(int i=0;i<root->children.size();i++){
        postorder(root->children[i]);
    }
    cout << root->data << " ";
}

//-----------------------------------NUM_OF_LEAF_NODES----------------------------------------------
int numLeafNodes(TreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    if(root->children.size()== 0){
        return 1;
    }
    int count = 0;
    for(int i=0;i<root->children.size();i++){
        count += numLeafNodes(root->children[i]);
    }
    return count;
}

//---------------------------------------DELETING_TREE_NODES----------------------------------------
//Instead use destructor for deleting
void deletetree(TreeNode<int>* root){
    if(root == NULL){
        return;
    }
    for(int i=0;i<root->children.size();i++){
        deletetree(root->children[i]);
    }
    delete root;
}

int main(){
    TreeNode<int>* root = takeInputLevelWise();

    /*
    TreeNode<int>* root = new TreeNode<int> (1);
    TreeNode<int>* node1 = new TreeNode<int> (2);
    TreeNode<int>* node2 = new TreeNode<int> (3);

    root->children.push_back(node1);
    root->children.push_back(node2);
    */
    
    printTreeLevelWise(root);
    cout << "Number of Nodes in this Tree: " << numNode(root) <<endl;
    cout << "Sum Total of each node is: " << sumNode(root) << endl;
    cout << "Largest Node in this tree is: " << largestNode(root) << endl;
    cout << "Height of this tree is: " << findHeight(root) << endl;
    printAtLevelK(root,2);cout << endl;
    preorder(root);cout << endl;
    postorder(root);cout << endl;
    cout << "Number of leaf nodes in this tree: " << numLeafNodes(root) << endl;
    deletetree(root);
    //Use destructor to delete the tree nodes not the above function that we made
    //By using destructors just call the delete inbuilt function

    delete root;
}