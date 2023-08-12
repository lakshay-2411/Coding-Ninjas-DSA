#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <climits>
#include "BinaryTreeNode.h"
using namespace std;

//---------------------------------------PRINT_TREE-------------------------------------------------
void printTree(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout << root->data << ":";
    if(root->left != NULL){
        cout << "L" << root->left->data;
    }
    if(root->right != NULL){
        cout << "R" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

//----------------------------------------TAKE_INPUT------------------------------------------------
BinaryTreeNode<int>* takeInput(){
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftChild = takeInput();
    BinaryTreeNode<int>* rightChild  = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

//--------------------------------------TAKE_INPUT_LEVEL_WISE---------------------------------------
BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << front->data << endl;
        int leftChild;
        cin >> leftChild;
        if(leftChild != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChild);
            front->left = child;
            pendingNodes.push(child);
        }
        cout << "Enter right child of " << front->data << endl;
        int rightChild;
        cin >> rightChild;
        if(rightChild != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChild);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

//---------------------------------PRINT_TREE_LEVEL_WISE-------------------------------------------
void printTreeLevelWise(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;;
    }
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        if(front->left != NULL){
            cout << "L:" << front->left->data << ",";
            pendingNodes.push(front->left);
        }else{
            cout << "L:" << "-1" << ",";
        }
        if(front->right != NULL){
            cout << "R:" << front->right->data;
            pendingNodes.push(front->right);
        }else{
            cout << "R:" << "-1";
        }
        cout << endl;
    }
}

//-------------------------------------------NUMBER_NODES-------------------------------------------
int numNodes(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    int ans = 1;
    ans += numNodes(root->left);
    ans += numNodes(root->right);
    return ans;
}

//-------------------------------------------CONTAINS_X---------------------------------------------
bool containsX(BinaryTreeNode<int>* root,int x){
    if(root == NULL) return false;
    if(root->data == x) return true;
    return containsX(root->left,x) || containsX(root->right,x); 
}

//-------------------------------------------HEIGHT_BT----------------------------------------------

/*APPROACH 1*/
int height1(BinaryTreeNode<int>* root){
    if(root == NULL) return 0;
    int L = height1(root->left);
    int R = height1(root->right);
    return max(L,R) + 1;
}

/*APPROACH 2*/
int height2(BinaryTreeNode<int>* root){
    if(root == NULL) return 0;
    int lh = height2(root->left);
    int rh = height2(root->right);
    if(lh > rh) return lh+1;
    else return rh+1;
}

/*APPROACH 3*/
int height3(BinaryTreeNode<int>* root){
    if(root == NULL) return 0;
    return 1 + max(height3(root->left),height3(root->right));
}

//-----------------------------------------MIRROR_BT------------------------------------------------
void mirrorTree(BinaryTreeNode<int>* root){
    if(root == NULL) return;
    BinaryTreeNode<int>* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirrorTree(root->left);
    mirrorTree(root->right);
}

//-----------------------------------------INORDER_TRAVERSAL----------------------------------------
void inorder(BinaryTreeNode<int>* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

//-----------------------------------------POSTORDER_TRAVERSAL--------------------------------------
void postorder(BinaryTreeNode<int>* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

//-----------------------------------------PREORDER_TRAVERSAL---------------------------------------
void preorder(BinaryTreeNode<int>* root){
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

//---------------------------------CONSTRUCT_TREE_FROM_TRAVERSALS-----------------------------------

/*USING INORDER AND PREORDER*/
BinaryTreeNode<int>* buildTreeHelper(int* in,int* pre,int inS,int inE,int preS,int preE){
    if(inS > inE) return NULL;
    int rootData = pre[preS];
    int rootIndex = -1;
    for(int i=inS;i<=inE;i++){
        if(in[i] == rootData){
            rootIndex = i;
            break;
        }
    }
    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPreS = preS + 1;
    int lPreE = lInE - lInS + lPreS;
    int rInS = rootIndex + 1;
    int rInE = inE;
    int rPreS = lPreE + 1;
    int rPreE = preE;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreeHelper(in,pre,lInS,lInE,lPreS,lPreE);
    root->right = buildTreeHelper(in,pre,rInS,rInE,rPreS,rPreE);
    return root;
}
BinaryTreeNode<int>* buildTree(int* in,int* pre,int size){
    return buildTreeHelper(in,pre,0,size-1,0,size-1);
}

/*------------------------------------------------------------------------------------------------*/

/*USING INORDER AND POSTORDER*/
BinaryTreeNode<int>* buildTreeHelper1(int* in,int* post,int inS,int inE,int postS,int postE){
    if(inS>inE || postS>postE) return NULL;
    int rootData = post[postE];
    int rootIndex =  -1;
    for(int i=inS;i<=inE;i++){
        if(in[i] == rootData){
            rootIndex = i;
            break;
        }
    }
    int lInS = inS;
    int lInE = rootIndex - 1;
    int rInS = rootIndex + 1;
    int rInE = inE;
    int lPostS = postS;
    int lPostE = lInE - lInS + lPostS;
    int rPostS = lPostE + 1;
    int rPostE = postE - 1;
    //int rPostE = rInE - rInS + rPostS;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreeHelper1(in,post,lInS,lInE,lPostS,lPostE);
    root->right = buildTreeHelper1(in,post,rInS,rInE,rPostS,rPostE);
    return root;
}

BinaryTreeNode<int>* buildTree1(int* in,int* post,int size){
    return buildTreeHelper1(in,post,0,size-1,0,size-1);
}
/*------------------------------------------------------------------------------------------------*/


//----------------------------------------DIAMETER_BT----------------------------------------------

/*APPROACH 1                                                                    T: O(N^2) S: O(N)*/

int diameter(BinaryTreeNode<int>* root){
    if(root == NULL) return 0;
    int option1 = height3(root->left) + height3(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);
    return max(option1,max(option2,option3));
}
/*------------------------------------------------------------------------------------------------*/

/*APPROACH 2                                                                     T: O(N) S: O(N)*/
pair<int,int> heightDiameter(BinaryTreeNode<int>* root){
    if(root == NULL){
        pair<int,int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int,int> leftAns = heightDiameter(root->left);
    pair<int,int> rightAns = heightDiameter(root->right);
    int lD = leftAns.second;
    int lH = leftAns.first;
    int rD = rightAns.second;
    int rH = rightAns.first;
    int height = max(lH,rH)+1;
    int diameter = max(lH+rH,max(lD,rD));
    pair<int,int> p;
    p.first = height;
    p.second = diameter;
    return p;
}

int helper(BinaryTreeNode<int>* root){
    pair<int,int> ans = heightDiameter(root);
    return ans.second;
}

/*------------------------------------------------------------------------------------------------*/


//------------------------------FINDING_MIN_MAX_IN_BT_SEPARATELY------------------------------------
int findMax(BinaryTreeNode<int> *root){
        //code here
    if(root == NULL){
        return INT_MIN;
    }
    int lA = findMax(root->left);
    int rA = findMax(root->right);
    return max(root->data,max(lA,rA));        
}
int findMin(BinaryTreeNode<int> *root){
        //code here
    if(root == NULL){
        return INT_MAX;
    }
    int lA = findMin(root->left);
    int rA = findMin(root->right);
    return min(root->data,min(lA,rA));
}

//------------------------------------MIN_MAX_USING PAIR_CLASS--------------------------------------

/*return both minimum and maximum value of node in BT*/

pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
	pair<int,int> p;
	if(root == NULL){
		p.first = INT_MAX;
		p.second = INT_MIN;
		return p;
	}
	pair<int,int> lA = getMinAndMax(root->left);
	pair<int,int> rA = getMinAndMax(root->right);
	
	p.first = min(root->data,min(lA.first,rA.first));
	p.second = max(root->data,max(lA.second,rA.second));
	return p;
}

//----------------------------------------SUM_OF_NODES----------------------------------------------
int sumNodes(BinaryTreeNode<int>* root){
    if(root == NULL) return NULL;
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}

//--------------------------------------------BALANCED_BT-------------------------------------------

/*APPROACH 1                                                                    T: O(N^2) S: O(N)*/
bool balanced(BinaryTreeNode<int>* root){
    if(root == NULL) return true;
    int lH = height3(root->left);
    int rH = height3(root->right);
    int diff = abs(lH-rH);
    if(diff>1) return false;
    bool a = balanced(root->left);
    bool b = balanced(root->right);
    return a&&b;
}

/*APPROACH 2                                                                     T: O(N) S: O(N)*/

pair<bool,int> isbalanced(BinaryTreeNode<int>* root){
    if(root == NULL){
        pair<bool,int> p;
        p.first = true;
        p.second = 0;
        return p;
    }
    pair<bool,int> leftAns = isbalanced(root->left);
    pair<bool,int> rightAns =  isbalanced(root->right);
    bool l = leftAns.first;
    int lA = leftAns.second;
    bool r = rightAns.first;
    int rA = rightAns.second;
    
    int depth = max(lA,rA)+1;
    bool ans = l&&r && abs(lA-rA)<=1;
    pair<bool,int> p;
    p.first = ans;
    p.second = depth;
    return p;
}

bool ans(BinaryTreeNode<int>* root){
    pair<bool,int> ans = isbalanced(root);
    return ans.first;
}

/*------------------------------------------------------------------------------------------------*/

//---------------------------------------REMOVE_LEAF_NODES------------------------------------------
BinaryTreeNode<int>* newTree(BinaryTreeNode<int>* root){
    if(root == NULL) return NULL;
    if(root->left == NULL&& root->right == NULL){
        //root = NULL;
        return root;
    }
    BinaryTreeNode<int>* leftRoot = newTree(root->left);
    BinaryTreeNode<int>* rightRoot = newTree(root->right);
    root->left = leftRoot;
    root->right = rightRoot;
    return root;
}

//------------------------------------NODES_WITHOUT_SIBLING----------------------------------------

void numSibling(BinaryTreeNode<int>* root){
    if(root == NULL) return;
    if(root->left==NULL) cout << root->left->data << " ";
    if(root->right==NULL) cout << root->left->data << " ";
    numSibling(root->left);
    numSibling(root->right);
    
}

//--------------------------------REMOVE_LEAF_NODES_EQUAL_TO_TARGET---------------------------------

BinaryTreeNode<int>* newTree(BinaryTreeNode<int>* root,int x){
    if(root == NULL) return NULL;
    if((root->left == NULL&& root->right == NULL)&&root->data == x){
        //root = NULL;
        return NULL;
    }
    root->left = newTree(root->left,x);
    root->right = newTree(root->right,x);
    return root;
}

/*------------------------------------------------------------------------------------------------*/

void numSibling(BinaryTreeNode<int>* root,vector<int>& ans){
    if(root == NULL) return;
    if(root->left==NULL && root->right!=NULL) ans.push_back(root->right->data);
    if(root->right==NULL && root->left!=NULL) ans.push_back(root->left->data);

    numSibling(root->left,ans);
    numSibling(root->right, ans);
}


vector<int> nodesWithoutSiblings(BinaryTreeNode<int> *root)
{
    // Write Your code here
    vector<int> ans;
    numSibling(root,ans);
    return ans;

}

/*------------------------------------------------------------------------------------------------*/


//----------------------------------------ZIG_ZAG_TRAVERSAL----------------------------------------

/*APPROACH 1                                                                    T: O(N^2) S: O(N)*/

void printlevelWise(BinaryTreeNode<int>* root){
    if(root == NULL) return;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    int level = 0;
    while(!q.empty()){
        int size = q.size();
        stack<int> s;
        for(int i=0;i<size;i++){
            BinaryTreeNode<int>* front = q.front();
            q.pop();
            if(level%2==0){
                cout << front->data << " ";
            }else{
                s.push(front->data);
            }
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
            while(!s.empty()){
                cout << s.top() << " ";
                s.pop();
            }
        level++;
        cout << endl;
    }
}

/*------------------------------------------------------------------------------------------------*/

/*Above approach using vectors*/
vector<vector<int>> zigzagLevelOrder(BinaryTreeNode<int>* root) {
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    int level = 0;
    while(!q.empty()){
        int size = q.size();
        stack<int> s;
        vector<int> vect;
        for(int i=0;i<size;i++){
            BinaryTreeNode<int>* front = q.front();
            q.pop();
            if(level%2==0){
                vect.push_back(front->data);
            }else{
                s.push(front->data);
            }
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
        while(!s.empty()){
                vect.push_back(s.top());
                s.pop();
            }
        ans.push_back(vect);
        level++;
    }
    return ans;
}

/*------------------------------------------------------------------------------------------------*/

/*APPROACH 2                                                                     T: O(N) S: O(N)*/

vector<int> zigzag(BinaryTreeNode<int>* root){
    vector<int> ans;
    if(root == NULL) return ans;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    bool leftToRight = true;
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            BinaryTreeNode<int>* front = q.front();
            q.pop();
            level.push_back(front->data);
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
        if(!leftToRight){
            reverse(level.begin(),level.end());
        }
        for(int i=0;i<level.size();i++){
            ans.push_back(level[i]);
        }
        leftToRight = !leftToRight;
    }
    return ans;
}


//----------------------------------ROOT_TO_NODE_PATH_IN_BT----------------------------------------
vector<int> reverse(vector<int> ans){
	vector<int> reversed;
    for (int i = ans.size() - 1; i >= 0; --i) {
        reversed.push_back(ans[i]);
    }
    return reversed;
}

vector<int> path(BinaryTreeNode<int>* root,int x){
	if(root == NULL){
		return {};
	}
	if(root->data == x){
		vector<int> p;
		p.push_back(root->data);
		return p;
	}
	vector<int> leftOutput = path(root->left,x);
	if(!leftOutput.empty()){
		leftOutput.push_back(root->data);
		return leftOutput;
	}
	vector<int> rightOutput = path(root->right,x);
	if(!rightOutput.empty()){
		rightOutput.push_back(root->data);
		return rightOutput;
	}else{
		return {};
	}
}

vector<int> pathInATree1(BinaryTreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int> output = path(root,x);
	return reverse(output);
	
}
/*------------------------------------------------------------------------------------------------*/
bool isPresent(BinaryTreeNode<int>* root, int x,vector<int>& ans){
	if(root == NULL) return false;
	ans.push_back(root->data);
	if(root->data == x) return true;
	if(isPresent(root->left,x,ans) || isPresent(root->right,x,ans)) return true;
	ans.pop_back();
	return false;
}

vector<int> pathInATree2(BinaryTreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int> ans;
	isPresent(root,x,ans);
	return ans;
}

//------------------------------------CHECK_COUSINS_IN_BT-----------------------------------------

pair<int,int> find(BinaryTreeNode<int>* root,int target,int depth = 0,int parent=-1){
        if(root==NULL) return {-1,-1};
        if(root->data==target) return {depth,parent};
        pair<int,int> lA = find(root->left,target,depth+1,root->data);
        if(lA.first!=-1)
            return lA;
        else
            return find(root->right,target,depth+1,root->data);
    }
    bool isCousins(BinaryTreeNode<int>* root, int x, int y) {
        pair<int,int> ans1 = find(root,x);
        pair<int,int> ans2 = find(root,y);
        return (ans1.first==ans2.first) && (ans1.second!=ans2.second);
    }

//--------------------------------LONGEST_LEAF_TO_ROOT_PATH----------------------------------------

vector<int>* longestPath(BinaryTreeNode<int>* root) {
	// Write your code here
    if(root==NULL){
        return new vector<int>();
    }
    vector<int>* lA = longestPath(root->left);
    vector<int>* rA = longestPath(root->right);
    if(lA->size()>rA->size()){
        lA->push_back(root->data);
        delete rA;
        return lA;
    }else{
        rA->push_back(root->data);
        delete lA;
        return rA;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    printTreeLevelWise(root);
    






    // root = newTree(root,3);

    //cout << helper(root) << endl;

    //cout << diameter(root) << endl;

    /*
    int in[] = {4,2,8,5,9,1,6,3,7};
    int pre[] = {1,2,4,5,8,9,3,6,7};
    int post[] = {4,8,9,5,2,6,7,3,1};
    BinaryTreeNode<int>* root = buildTree1(in,post,9);
    printTreeLevelWise(root);
    */

    //postorder(root);
    //preorder(root);
    //inorder(root);
    
    /*
    mirrorTree(root);
    printlevelWise(root);
    */
    
    /*
    vector<int> ans = levelOrder(root);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    */

    //cout << "Height: " << height2(root) << endl;

    /*
    int x; cin >>x;
    cout << containsX(root,x) <<endl;
    */

    //cout << numNodes(root);

    /*
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
    root->left = node1;
    root->right = node2;
    printTree(root);
    */
   delete root;
}