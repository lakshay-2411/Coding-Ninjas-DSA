#include <iostream>
#include <vector>
#include <climits>
#include "TreeNode.h"
using namespace std;

//--------------------------------------PRINT_TREE--------------------------------------------------
void printTreeLevelWise(TreeNode<int>* root){
    if(root == NULL){
        return;
    }
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << " ";
        // for(int i =0;i<front->children.size();i++){
        //     cout << front->children[i]->data << ",";
        // }
        // cout << endl;
        for(int i=0;i<front->children.size();i++){
            pendingNodes.push(front->children[i]);
        }
    }
}

//-------------------------------------CONTAINS_X---------------------------------------------------
bool containsX(TreeNode<int>* root,int x){
    if(root == NULL){
        return false;
    }
    if(root->data == x){
        return true;
    }
    bool found = false;
    for(int i =0;i<root->children.size();i++){
        found = containsX(root->children[i],x);
    }
    return found;
}

//--------------------------------------NUM_NODES_GREATER_X-----------------------------------------
int numNodesGreaterX(TreeNode<int>* root,int x){
    if(root == NULL){
        return 0;
    }
    int num = 0;
    if(root->data > x){
        num++;
    }
    for(int i=0;i<root->children.size();i++){
        num += numNodesGreaterX(root->children[i],x);
    }
    return num;   
}

//---------------------------------MAX_CHILD_SUM------------------------------------------------
int res = 0;
int maxChildSum(TreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    int ans = root->data;
    for(int i=0;i<root->children.size();i++){
        ans += root->children[i]->data;
    }
    for(int i=0;i<root->children.size();i++){
        int childSum = maxChildSum(root->children[i]);
        if(childSum > ans){
            ans = childSum;
            res = root->children[i]->data;
        }
    }
    return ans;
}

//---------------------------------STRUCTURALLY_IDENTICAL-------------------------------------------
bool identical(TreeNode<int>* root1, TreeNode<int>* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if((root1->children.size() != root2->children.size()) || (root1->data != root2->data)){
        return false;
    }
    for(int i=0;i<root1->children.size();i++){
        if(!identical(root1->children[i],root2->children[i])){
            return false;
        }
    }
    return true;
}

//------------------------------------REPLACE_WITH_DEPTH-------------------------------------------
void help(TreeNode<int>* root,int depth){
    root->data = depth;
    for(int i=0;i<root->children.size();i++){
        help(root->children[i],depth+1);
    }
}

void replaceDepth(TreeNode<int>* root){
    if(root == NULL) return;
    int depth = 0;
    help(root,depth);
}

//-------------------------------------NEXT_LARGER_THAN_N-------------------------------------------
int largerThanN(TreeNode<int>* root, int n){
    if(root == NULL) return -1;
    int num = INT_MAX;
    if(root->data > n) num = root->data;
    for(int i=0;i<root->children.size();i++){
        int ans = largerThanN(root->children[i],n);
        if(ans > n &&  ans < num) num = ans;
    }
    return num;
}

//----------------------------------NEXT_LARGER_THAN_N----------------------------------------------
TreeNode<int>* nextLarger(TreeNode<int>* root,int n){
    if(root == NULL){
        return NULL;
    }
    TreeNode<int>* ans = NULL;
    if(root->data > n) ans = root;
    for(int i =0;i<root->children.size();i++){
        TreeNode<int>* child = nextLarger(root->children[i],n);
        if(child != NULL){
            if(ans == NULL || child->data < ans->data) ans = child;
        }
    }
    return ans;
}

//-------------------------------------REMOVE_LEAF_NODES------------------------------------------
TreeNode<int>* removeLeafNodes(TreeNode<int>* root){
    if(root==NULL){
        return  NULL;
    }
    if(root->children.size() == 0){
        delete root;
        return NULL;
    }
    for(int i=0;i<root->children.size();i++){
        root->children[i] = removeLeafNodes(root->children[i]);
    }
    return root;
}
int main(){
    TreeNode<int>* root = takeInputLevelWise();
    printTreeLevelWise(root);
    TreeNode<int>* ans = removeLeafNodes(root);cout << endl;
    printTreeLevelWise(ans);




    // int n; cin >> n;
    // TreeNode<int>* ans = nextLarger(root,n);
    // if(ans != NULL) cout << ans->data;
    // else cout << "NULL" << endl;

    /*
    cout << maxChildSum(root) << endl;
    cout << res;
    */
}