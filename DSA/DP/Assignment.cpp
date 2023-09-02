#include <iostream>
#include <vector>
using namespace std;

int lootHouses_2(int arr[],int n){
    if(n < 0){
        return 0;
    }
    vector<int> dp(n,-1);
    dp[0] = arr[0];
    dp[1] = max(arr[0],arr[1]);
    for(int i=2;i<=n;i++){
        dp[i] = max(dp[i-1],dp[i-2]);
    }
    return dp[n];
}

int lootHouses_1helper(int arr[],int *ans,int n){
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return arr[0];
    }
    if(ans[n] != -1){
        return ans[n];
    }
    int a = arr[n] + lootHouses_1helper(arr,ans,n-2);
    int b = lootHouses_1helper(arr,ans,n-1);
    ans[n] = max(a,b);
    return ans[n];
}

int lootHouses_1(int arr[],int n){
    int *ans = new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i] = -1;
    }
    return lootHouses_1helper(arr,ans,n);
}

int lootHouses(int arr[],int n){
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return arr[0];
    }
    int currentPick = arr[n] + lootHouses(arr,n-2);
    int currentNotPick = lootHouses(arr,n-1);

    return max(currentPick,currentNotPick);
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << lootHouses_2(arr,n-1);
}