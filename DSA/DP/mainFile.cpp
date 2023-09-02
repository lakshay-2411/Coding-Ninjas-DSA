#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
using namespace std;

//---------------------------------------EDIT_DISTANCE-------------------------------------------//


//Method 3--------------DYNAMIC PROGRAMMING(Bottom Up Approach)---------------Time Complexity : O(N)
int edit_distance_DP(string s,string t){
    int m = s.length();
    int n = t.length();
    int** dp = new int*[m+1];
    for(int i=0;i<=m;i++){
        dp[i] = new int[n+1];
    }

}

//Method 2------------------MEMOIZATION(Top to Bottom Approach)--------------Time Complexity : O(N)
int edit_distance_1helper(string s,string t,int** output){
    int m = s.length();
    int n = t.length();
    // Base case
    if(s.length() == 0 || t.length() == 0){
        return max(s.size(),t.size());
    }
    // Check if ans already exists
    if(output[m][n] != -1){
        return output[m][n];
    }
    int ans;
    // Recursive calls
    if(s[0] == t[0]){
        ans = edit_distance_1helper(s.substr(1),t.substr(1),output);
    }else{
        // insert
        int a = 1 + edit_distance_1helper(s.substr(1),t,output);
        // delete
        int b = 1 + edit_distance_1helper(s,t.substr(1),output);
        // replacing
        int c = 1 + edit_distance_1helper(s.substr(1),t.substr(1),output);
        ans = min(a,min(b,c));
    }
    output[m][n] = ans;
    return ans;

}

int edit_distance_1(string s,string t){
    int m = s.length();
    int n = t.length();
    int** output = new int*[m+1];
    for(int i=0;i<=m;i++){
        output[i] = new int[n+1];
        for(int j=0;j<=n;j++){
            output[i][j] = -1;
        }
    }
    return edit_distance_1helper(s,t,output);
}

//Method 1--------------------BRUTE_FORCE_APPROACH-------------------------Time Complexity : O(3^n)
int edit_distance(string s,string t){
    if(s.length() == 0 || t.length() == 0){
        return max(s.size(),t.size());
    }
    if(s[0] == t[0]){
        return edit_distance(s.substr(1),t.substr(1));
    }else{
        // Insert 
        int a = 1 + edit_distance(s.substr(1),t);
        // Delete
        int b = 1 + edit_distance(s,t.substr(1));
        // Replace
        int c = 1 + edit_distance(s.substr(1),t.substr(1));
        return min(a,min(b,c));
    }
}

//---------------------------------LONGEST_COMMON_SUBSEQUENCE------------------------------------//


//Method 3--------------DYNAMIC PROGRAMMING(Bottom Up Approach)---------------Time Complexity : O(N)
int lcs_DP(string s,string t){
    int m = s.length();
    int n = t.length();
    int** dp = new int*[m+1];
    for(int i=0;i<=m;i++){
        dp[i] = new int[n+1];
    }

    // Fill 1st row
    for(int i=0;i<=n;i++){
        dp[0][i] = 0;
    }
    // Fill 1st column
    for(int j=0;j<=m;j++){
        dp[j][0] = 0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            // Check if 1st char matches
            if(s[m-i] == t[n-j]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i][j-1],max(dp[i-1][j],dp[i-1][j-1]));
            }
        }
    }
    return dp[m][n];
}

//Method 2------------------MEMOIZATION(Top to Bottom Approach)--------------Time Complexity : O(N)
int lcs_1helper(string s,string t,int** output){
    int m = s.length();
    int n = t.length();
    // Base case
    if(s.length() == 0 || t.length() == 0){
        return 0;
    }
    // Check if ans already exists
    if(output[m][n] != -1){
        return output[m][n];
    }

    int ans;
    // Recursive calls
    if(s[0] == t[0]){
        ans = 1 + lcs_1helper(s.substr(1),t.substr(1),output);
    }else{
        int a = lcs_1helper(s,t.substr(1),output);
        int b = lcs_1helper(s.substr(1),t,output);
        ans = max(a,b);
    }
    output[m][n] = ans;
    return ans;
}

int lcs_1(string s,string t){
    int m = s.length();
    int n = t.length();
    int** output = new int*[m+1];
    for(int i=0;i<=m;i++){
        output[i] = new int[n+1];
        for(int j=0;j<=n;j++){
            output[i][j] = -1;
        }
    }
    return lcs_1helper(s,t,output);
}

//Method 1---------------------BRUTE_FORCE_APPROACH-------------------------Time Complexity : O(2^n)
int lcs(string s, string t){
    if(s.length() == 0 || t.length() == 0){
        return 0;
    }
    if(s[0] == t[0]){
        return 1 + lcs(s.substr(1),t.substr(1));
    }else{
        int a = lcs(s,t.substr(1));
        int b = lcs(s.substr(1),t);
        return max(a,b);
    }
}

//----------------------------------------MIN_COST_PATH-------------------------------------------//


//Method 3--------------DYNAMIC PROGRAMMING(Bottom Up Approach)---------------Time Complexity : O(N)
int minCostPath_DP(int** input,int m,int n){
    int** dp = new int*[m];
    for(int i=0;i<m;i++){
        dp[i] = new int[n];
    }

    // Fill the last cell i.e destination
    dp[m-1][n-1] = input[m-1][n-1];

    // Fill last row (right to left)
    for(int j=n-2;j>=0;j--){
        dp[m-1][j] = dp[m-1][j+1] + input[m-1][j];
    }

    // Fill last column (bottom to top)
    for(int i=m-2;i>=0;i--){
        dp[i][n-1] = dp[i+1][n-1]+ input[i][n-1];
    }

    // Fill remaining cells
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            dp[i][j] = min(dp[i+1][j] , min(dp[i+1][j+1],dp[i][j+1])) + input[i][j];
        }
    }

    return dp[0][0];
}

//Method 2------------------MEMOIZATION(Top to Bottom Approach)--------------Time Complexity : O(N)
int minCostPath_1helper(int** input,int** memo,int m,int n,int i,int j){
    if(i == m-1 && j == n-1){
        return input[i][j];
    }
    if(i >= m || j >= n){
        return INT_MAX;
    }
    if(memo[i][j] != -1){
        return memo[i][j];
    }
    int x = minCostPath_1helper(input,memo,m,n,i,j+1);
    int y = minCostPath_1helper(input,memo,m,n,i+1,j);
    int z = minCostPath_1helper(input,memo,m,n,i+1,j+1);
    memo[i][j] = min(x,min(y,z)) + input[i][j];
    return memo[i][j];
}

int minCostPath_1(int** input,int m,int n,int i,int j){
    int **memo = new int*[m];
    for(int i=0;i<m;i++){
        memo[i] = new int[n];
        for(int j=0;j<n;j++){
            memo[i][j] = -1;
        }
    }
    return minCostPath_1helper(input,memo,m,n,i,j);
}

//Method 1---------------------BRUTE_FORCE_APPROACH-------------------------Time Complexity : O(3^n)
int minCostPath(int** input,int m,int n,int i,int j){
    if(i == m-1 && j == n-1){
        return input[i][j];
    }
    if(i >= m || j >= n){
        return INT_MAX;
    }
    int x = minCostPath(input,m,n,i,j+1);
    int y = minCostPath(input,m,n,i+1,j);
    int z = minCostPath(input,m,n,i+1,j+1);
    return min(x,min(y,z)) + input[i][j];
}

int main(){

    string s = "abc";
    string t = "dc";
    cout << edit_distance_1(s,t);

    /*
    int m,n;
    cin >> m >> n;
    int **input = new int*[m];
    for(int i=0;i<m;i++){
        input[i] = new int[n];
        for(int j=0;j<n;j++){
            cin >> input[i][j];
        }
    }
    */

    //cout << minCostPath_DP(input,m,n) << endl;
}