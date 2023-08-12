#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include "BSTNode.h"
using namespace std;

//--------------------------------------SEARCH_A_NODE----------------------------------------------
bool search(BinaryTreeNode<int>* root, int x) {
    // Your code here
    if(root == NULL) return  false;
    if(root->data == x) return true;
    else if(root->data < x) return search(root->right,x);
    else return search(root->left,x);
}

//Returning the searched node
BinaryTreeNode<int>* searchBST(BinaryTreeNode<int>* root, int val) {
    if(root == NULL){
            return NULL;
    }
    if(root->data == val){
        return root;
    }
    if(val>root->data){
        return searchBST(root->right,val);
    }
    else return searchBST(root->left,val);
}

//---------------------------PRINT_BST_ELEMENTS_BETWEEN_GIVEN_RANGE--------------------------------

/*Print elements in increasing order*/
void helper(BinaryTreeNode<int>* root,int low,int high,vector<int>& ans){
    if(root == NULL){
        return;
    }
    helper(root->left,low,high,ans);
    if(low<=root->data && high>=root->data){
        ans.push_back(root->data);
    }
    helper(root->right,low,high,ans);
}

/*Printing elements using BST property*/
void helper1(BinaryTreeNode<int>* root,int low,int high,vector<int>& ans){
        if(root == NULL){
            return;
        }
        if(low<=root->data && high>=root->data){
            ans.push_back(root->data);
        }
        if(root->data > low){
            helper(root->left,low,high,ans);
        }
        if(root->data <= high){
            helper(root->right,low,high,ans);
        }
    }

vector<int> printNearNodes(BinaryTreeNode<int> *root, int low, int high) {
        //code here
    vector<int> ans;
    helper(root,low,high,ans);
    return ans;
}

//--------------------------------------CHECK_BST--------------------------------------------------

/*Approach 1                                                                 T: O(N^2) S: O(N)*/

bool isBST(BinaryTreeNode<int>* root){
    if(root == NULL){
        return true;
    }
    int leftMax = findMax(root->left);
    int rightMin = findMin(root->right);;
    bool output = (root->data>leftMax)&&(root->data<=rightMin)&&(isBST(root->left))&&(isBST(root->right));
    return output;
}

/*Approach 2                        USING_PAIR_CLASS                           T: O(N) S: O(N)*/

class isBSTReturn{
    public:
    bool isBST;
    int minimum;
    int maximum;
};

isBSTReturn isBST2(BinaryTreeNode<int>* root){
    if(root == NULL){
        isBSTReturn output;
        output.isBST = true;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        return output;
    }
    isBSTReturn leftOutput = isBST2(root->left);
    isBSTReturn rightOutput = isBST2(root->right);
    int minimum = min(root->data,min(leftOutput.minimum,rightOutput.minimum));
    int maximum = max(root->data,max(leftOutput.maximum,rightOutput.maximum));
    bool isBSTFinal = (root->data>leftOutput.maximum)&&(root->data<=rightOutput.minimum)&&leftOutput.isBST&&rightOutput.isBST;
    isBSTReturn output;
    output.isBST = isBSTFinal;
    output.maximum = maximum;
    output.minimum = minimum;
    return output;
}

/*Approach 3                         TOP_TO_BOTTOM_APPROACH                     T: O(N) S: O(N)*/

bool isBST3(BinaryTreeNode<int>* root,int min=INT_MIN,int max = INT_MAX){
    if(root == NULL){
        return true;
    }
    if(root->data < min || root->data > max){
        return false;
    }
    bool isLeftOk = isBST3(root->left,min,root->data);
    bool isRightOk = isBST3(root->right,root->data,max);
    return isLeftOk&&isRightOk;
}

//-----------------------------CONSTRUCT_BST_FROM_SORTED_ARRAY--------------------------------------

BinaryTreeNode<int>* constructTree(int *arr,int s,int e){
    if(s>e) return NULL;
    int mid = (s+e)/2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(arr[mid]);
    root->left = constructTree(arr,s,mid-1);
    root->right = constructTree(arr,mid+1,e);
    return root;
}

//--------------------------------------BST_TO_SORTED_LL-------------------------------------------

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        next = NULL;
    }
};

/*-------------Method 1------------*/

pair<Node*,Node*> helper(BinaryTreeNode<int>* root){
    if(root == NULL){
        pair<Node*,Node*> p;
        p.first = NULL;
        p.second = NULL;
        return p;
    }
    Node* newNode = new Node(root->data);
    pair<Node*,Node*> leftAns = helper(root->left);
    pair<Node*,Node*> rightAns = helper(root->right);
    
    if(leftAns.first == NULL){
        leftAns.first = newNode;
        leftAns.second = newNode;
    }else{
        leftAns.second->next = newNode;
        leftAns.second = newNode;
    }
    if(rightAns.first == NULL){
        rightAns.first = newNode;
        rightAns.second = newNode;
    }else{
        newNode->next = rightAns.first;
    }
    return {leftAns.first,rightAns.second};
}
Node* buildLL(BinaryTreeNode<int>* root){
    pair<Node*,Node*> ans = helper(root);
    return ans.first;
}

/*------------Method 2------------*/

pair<Node*,Node*> util(BinaryTreeNode<int>* root){
    if(root == NULL){
        return {NULL,NULL};
    }
    Node* newNode = new Node(root->data);
    
    pair<Node*,Node*> LA = util(root->left);
    pair<Node*,Node*> RA = util(root->right);
    
    pair<Node*,Node*> p;
    if(LA.first == NULL&&RA.first == NULL){
        p.first = newNode;
        p.second = newNode;
    }else if(LA.first == NULL&&RA.first!=NULL){
        p.first = newNode;
        newNode->next = RA.first;
        p.second = RA.second;
    }else if(LA.first!= NULL&&RA.first==NULL){
        p.first = LA.first;
        LA.second->next = newNode;
        p.second = newNode;
    }else{
        p.first = LA.first;
        LA.second->next = newNode;
        newNode->next = RA.first;
        p.second = RA.second;
    }
    return p;
}
Node* constructLL(BinaryTreeNode<int>* root){
    pair<Node*,Node*> ans = util(root);
    return ans.first;
}

//--------------------------------CREATE_INSERT_DUPLICATE_NODE--------------------------------------
void insertDuplicate(BinaryTreeNode<int>* root){
    if(root == NULL) return;
    BinaryTreeNode<int>* duplicate = new BinaryTreeNode<int>(root->data);
    duplicate->left = root->left;
    root->left = duplicate;
    insertDuplicate(duplicate->left);
    insertDuplicate(root->right);

}

//--------------------------------------PAIR_SUM_IN_BT_AND_BST--------------------------------------
void convert(BinaryTreeNode<int>* root,vector<int>& ans){
    if(root==NULL) return;
    convert(root->left,ans);
    ans.push_back(root->data);
    convert(root->right,ans);
}

void pairSum(BinaryTreeNode<int>* root,int key){
    if(root==NULL) return;
    vector<int> ans;
    convert(root,ans);
    //if this is a bst then inorder traversal is enough no need to sort then//
    sort(ans.begin(),ans.end());
    int i=0;
    int j=ans.size()-1;
    while(i<j){
        if(ans[i]+ans[j]==key){
            cout << ans[i] << " " << ans[j] << endl;
            i++;
            j++;
        }else if(ans[i]+ans[j]>key){
            j--;
        }else{
            i++;
        }
    }
}

//---------------------------------PRINT_NODES_SUM_TO_S---------------------------------------------
vector<vector<int>> printNodesSumToS(BinaryTreeNode<int> *root, int s)
{
    // Write your code here.
    vector<vector<int>> arr;
    if(root==NULL){
        arr.push_back({-1,-1});
        return arr;
    }
    vector<int> ans;
    
    convert(root,ans);
    int i=0;
    int j=ans.size()-1;
    while(i<j){
        if(ans[i]+ans[j]==s){
            vector<int> pair = {ans[i],ans[j]};
            arr.push_back(pair);
            i++;
            j--;
        }else if(ans[i]+ans[j]>s){
            j--;
        }else{
            i++;
        }
    }
    if(arr.empty()){
        arr.push_back({-1,-1});
    }
    return arr;

}


//----------------------------------------LCA_BT----------------------------------------------------
BinaryTreeNode<int>* lowestCommonAncestorBT(BinaryTreeNode<int>* root,BinaryTreeNode<int>* p,BinaryTreeNode<int>* q){
    if(root==NULL){
            return NULL;
        }
        if(root->data==p->data || root->data==q->data){
            return root;
        }
        BinaryTreeNode<int>* left = lowestCommonAncestorBT(root->left,p,q);
        BinaryTreeNode<int>* right = lowestCommonAncestorBT(root->right,p,q);
        if(left!=NULL && right!=NULL){
            return root;
        }
        if(left==NULL && right!=NULL){
            return right;
        }
        if(left!=NULL && right==NULL){
            return left;
        }
        return NULL;
}

//---------------------------------------LCA_BST----------------------------------------------------
BinaryTreeNode<int>* lowestCommonAncestorBST(BinaryTreeNode<int>* root, BinaryTreeNode<int>* p, BinaryTreeNode<int>* q) {
        while(root!=NULL){
            if(p->data<root->data && q->data<root->data) root=root->left;
            else if(p->data>root->data && q->data>root->data) root=root->right;
            else return root;
        }
        return NULL;
}
BinaryTreeNode<int>* LCAinaBST(BinaryTreeNode<int>* root,BinaryTreeNode<int>* p,BinaryTreeNode<int>* q){
    if(root==NULL){
        return NULL;
    }
    if(p->data>root->data && q->data>root->data){
        return LCAinaBST(root->right,p,q);
    }else if(p->data<root->data && q->data<root->data){
        return LCAinaBST(root->left,p,q);
    }
    return root;
}

//-----------------------------------LARGEST_BST_IN_BT----------------------------------------------

/*                    Returning the number of nodes of largest bst                             */

class Pair{
    public:
    int maximum;
    int minimum;
    int size;
    bool isBST;
    int height;
};
Pair largestBST(BinaryTreeNode<int>* root,int & ans){
    if(root==NULL){
        Pair obj;
        obj.maximum = INT_MIN;
        obj.minimum = INT_MAX;
        obj.size = 0;
        obj.isBST = true;
        return  obj;
    }
    Pair leftOutput = largestBST(root->left,ans);
    Pair rightOutput = largestBST(root->right,ans);
    int minimum = min(root->data,min(leftOutput.minimum,rightOutput.minimum));
    int maximum = max(root->data,max(leftOutput.maximum,rightOutput.maximum));
    bool isBSTFinal = (root->data>leftOutput.maximum)&&(root->data<=rightOutput.minimum)&&leftOutput.isBST&&rightOutput.isBST;
    Pair obj;
    obj.minimum = minimum;
    obj.maximum = maximum;
    obj.isBST = isBSTFinal;
    if(isBSTFinal){
        obj.size = leftOutput.size+rightOutput.size+1;
        ans = max(ans,obj.size);
    }else{
        obj.size = leftOutput.size+rightOutput.size;
    }
    return obj;
}

int largestBSTSize(BinaryTreeNode<int>* root){
    if(root==NULL) return 0;
    int ans = 0;
    Pair p = largestBST(root,ans);
    return ans;
}
//--------------------------------------------------------------------------------------------------
/*                         Returning the height of Largest bst                                */
Pair BST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        Pair obj;
        obj.minimum = INT_MAX;
        obj.maximum = INT_MIN;
        obj.isBST = true;
        obj.height = 0;
        return obj;
    }

    Pair left = BST(root->left);
    Pair right = BST(root->right);

    int minimum = min(root->data, min(left.minimum, right.minimum));
    int maximum = max(root->data, max(left.maximum, right.maximum));
    bool isBSTfinal = (root->data > left.maximum) && (root->data < right.minimum) && left.isBST && right.isBST;

    Pair obj;
    obj.minimum = minimum;
    obj.maximum = maximum;
    obj.isBST = isBSTfinal;
    if (isBSTfinal)
    {
        obj.height = 1 + max(left.height, right.height);
    }
    else
        obj.height = max(left.height, right.height);
    return obj;
}

int largestBSTSubtree(BinaryTreeNode<int> *root)
{
    // Write your code here
    return BST(root).height;
}

/*
                        REPLACE WITH SUM OF GREATER NODES
*/

//---------------------------BST_TO_GREATER_BST_INCLUDING_ROOTdATA----------------------------------
void replace(BinaryTreeNode<int>* root,int &sum){
    if(root==NULL){
        return;
    }
    replace(root->right,sum);
    sum = sum+root->data;
    root->data = sum;
    replace(root->left,sum);
}

//-------------------------BST_TO_GREATER_BST_EXCLUDING_ROOTdATA------------------------------------
void replace1(BinaryTreeNode<int>* root,int &sum){
  if (root == NULL) {
    return;
  }
  replace1(root->right,sum);
    sum = sum+root->data;
    root->data = sum-root->data;
    replace1(root->left,sum);
}
void convertBST(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    int sum=0;
    replace(root,sum);
}

//----------------------------------PATH_SUM_ROOT_TO_LEAF------------------------------------------

/*For a given Binary Tree of type integer and a number K, print out all root-to-leaf paths where 
the sum of all the node data along the path is equal to K.*/

vector<vector<int>> ans;
    void pathHelper(BinaryTreeNode<int>* root,int targetSum,vector<int> result){
        if(root==NULL){
            return;
        }
        result.push_back(root->data);
        if(root->data == targetSum && root->left==NULL&&root->right==NULL){
            ans.push_back(result);
        }
        pathHelper(root->left,targetSum-root->data,result);
        pathHelper(root->right,targetSum-root->data,result);
        result.pop_back();
    }

    vector<vector<int>> pathSum(BinaryTreeNode<int>* root, int targetSum) {
        if(root==NULL){
            return ans;
        }
        vector<int> result;
        pathHelper(root,targetSum,result);
        return ans;
    }

//--------------------------Print nodes at distance k from node---------------------------------


int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    printlevelWise(root);
    cout << largestBSTSize(root);
}