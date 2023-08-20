#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
using namespace std;

//--------------------------------NUM_BALANCED_BINARY_TREES---------------------------------------//


//Method 3--------------DYNAMIC PROGRAMMING(Bottom Up Approach)---------------Time Complexity : O(N)
int numBT_3(int h){
    long long *dp = new long long[h+1];
    dp[0] = dp[1] = 1;
    int mod = 1e9 + 7;
    for(int i=2;i<=h;i++){
        long long x = dp[i-1] % mod;
        long long y = dp[i-2] % mod;
        long long temp1 = (x * x) % mod;
        long long temp2 = (2*x * y) % mod;
        dp[i] = (temp1 + temp2) % mod;
    }
    return (int)dp[h];
}

//Method 2-----------------MEMOIZATION(Top to Bottom Approach)--------------Time Complexity : O(N)
int numBT_1helper(int h,vector<int> ans){
    if(h <= 1){
        return 1;
    }
    if(ans[h] != -1){
        return ans[h];
    }
    long long int x = numBT_1helper(h-1,ans);
    long long int y = numBT_1helper(h-2,ans);
    long long int mod = 1e9 + 7;

    long long int temp1 = (x * x) % mod;
    long long int temp2 = (2 * x * y) % mod;
    ans[h] = (temp1 + temp2) % mod;
    return ans[h];

}

int numBT_1(int h){
    vector<int> ans(h+1,-1);
    return numBT_1helper(h,ans);
}

//Method 1--------------------BRUTE_FORCE_APPROACH-------------------------Time Complexity : O(2^n)
long long int numBT(int h){
    if(h <= 1){
        return 1;
    }

    long long int x = numBT(h-1);
    long long int y = numBT(h-2);
    long long int mod = 1e9 + 7;

    long long int temp1 = (x * x) % mod;
    long long int temp2 = (2 * x * y) % mod;
    long long int ans = (temp1 + temp2) % mod;

    //int ans = (l*l + 2*l*r)%mod;
    return ans;
}

//--------------------------------------MIN_COUNT-------------------------------------------------//


//Method 3--------------DYNAMIC PROGRAMMING(Bottom Up Approach)---------------Time Complexity : O(N)
int minCount_3(int n){
    vector<int> dp(n+1,INT_MAX);

    dp[0] = 0;

    for(int i=1;i<=n;i++){
        int j = 1;
        while(j * j <= i){
            dp[i] = min(dp[i],dp[i-j*j]+1);
            j++;
        }
    }
    return dp[n];
}

//Method 2-----------------MEMOIZATION(Top to Bottom Approach)--------------Time Complexity : O(N)
int minCount_2helper(int n,int *ans){
    if(n == 0){
        return 0;
    }
    if(ans[n] != -1){
        return ans[n];
    }
    int res = INT_MAX;
    for(int i=1;i*i<=n;i++){
        ans[n] = res = min(res,minCount_2helper(n-i*i,ans));
    }
    ans[n] = res + 1;
    return ans[n];
}

int minCount_2(int n){
    int *ans = new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i] = -1;
    }
    return minCount_2helper(n,ans);
}

//Method 1--------------------BRUTE_FORCE_APPROACH-------------------------Time Complexity : O(2^n)
int minCount(int n){
    if(n <= 3){
        return n;
    }
    int res = INT_MAX;
    for(int i=1;i*i<=n;i++){
        res = min(res,minCount(n - i * i));
    }
    return res + 1;
}


//-------------------------------------------STAIRCASE-------------------------------------------//


//Method 3--------------DYNAMIC PROGRAMMING(Bottom Up Approach)---------------Time Complexity : O(N)
int stairs_3(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    int *ans = new int[n+1];
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 2;
    for(int i=3;i<=n;i++){
        ans[i] = ans[i-1] + ans[i-2] + ans[i-3];
    }
    return ans[n];
}

//Method 2-----------------MEMOIZATION(Top to Bottom Approach)--------------Time Complexity : O(N)
int stairs_2helper(int n,int *ans){
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return 1;
    }
    if(ans[n] != -1){
        return ans[n];
    }
    int x = stairs_2helper(n-1,ans);
    int y = stairs_2helper(n-2,ans);
    int z = stairs_2helper(n-3,ans);

    ans[n] = x+y+z;

    return ans[n];
}

int stairs_2(int n){
    int *ans = new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i] = -1;
    }
    return stairs_2helper(n,ans);
}

//Method 1--------------------BRUTE_FORCE_APPROACH-------------------------Time Complexity : O(3^n)
int stairs(int n){
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return 1;
    }
    return stairs(n-1) + stairs(n-2) + stairs(n-3);
}


//--------------------------------------MIN_STEPS_TO_1-------------------------------------------//


//Method 3--------------DYNAMIC PROGRAMMING(Bottom Up Approach)---------------Time Complexity : O(N)
int minSteps3(int n){
    int *ans = new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i] = INT_MAX;
    }
    ans[0] = 0;
    ans[1] = 0;

    for(int i=2;i<=n;i++){
        ans[i] = min(ans[i],ans[i-1] + 1);
        if(i % 2 == 0){
            ans[i] = min(ans[i],ans[i/2] + 1);
        }
        if(i % 3 == 0){
            ans[i] = min(ans[i],ans[i/3] + 1);
        }
    }

    return ans[n];
}

//Method 2-----------------MEMOIZATION(Top to Bottom Approach)--------------Time Complexity : O(N)
int minSteps2_helper(int n,int *ans){
    if(n <= 1){
        return 0;
    }
    // Check if output already exists
    if(ans[n] != -1){
        return ans[n];
    }
    
    int x = minSteps2_helper(n-1,ans);
    int y = INT_MAX;
    if(n % 2 == 0){
        y = minSteps2_helper(n/2,ans);
    }
    int z = INT_MAX;
    if(n % 3 == 0){
        z = minSteps2_helper(n/3,ans);
    }

    // Save the output for future use
    ans[n] = min(x,min(y,z)) + 1;

    // Return the final output
    return ans[n];
}

int minSteps2(int n){
    int *ans = new int[n+1];

    for(int i=0;i<=n;i++){
        ans[i] = -1;
    }
    return minSteps2_helper(n,ans);
}

//Method 1--------------------BRUTE_FORCE_APPROACH-------------------------Time Complexity : O(3^n)
int minSteps1(int n){
    if(n <= 1){
        return 0;
    }
    int x = minSteps1(n-1);
    int y = INT_MAX;
    if(n % 2 == 0){
        y = minSteps1(n/2);
    }
    int z = INT_MAX;
    if(n % 3 == 0){
        z = minSteps1(n/3);
    }
    return min(x,min(y,z)) + 1;
}


//----------------------------------Nth_FIBONACCI_NUMBER-----------------------------------------//


//Method 3-------------DYNAMIC PROGRAMMING(Bottom Up Approach)----------------Time Complexity : O(N)
int fibo_3(int n){
    int *ans = new int[n+1];

    ans[0] = 0;
    ans[1] = 1;

    for(int i=2;i<=n;i++){
        ans[i] = ans[i-1] + ans[i-2];
    }

    return ans[n];
}

//Method 2-----------------MEMOIZATION(Top to Bottom Approach)---------------Time Complexity : O(N)
int fibo_2helper(int n,int *ans){
    if(n <= 1){
        return n;
    }

    // Check if output already exists
    if(ans[n] != -1){
        return ans[n];
    }
    int a = fibo_2helper(n-1,ans);
    int b = fibo_2helper(n-2,ans);

    // Save the output for future use
    ans[n] = a + b;

    // Return the final output
    return ans[n];
}

int fibo_2(int n){
    int * ans = new int[n+1];
    
    for(int i=0;i<=n;i++){
        ans[i] = -1;
    }
    return fibo_2helper(n,ans);
}

//Method 1--------------------BRUTE_FORCE_APPROACH--------------------------Time Complexity : O(2^n)
int fibo(int n){
    if(n <= 1){
        return n;
    }
    int a = fibo(n-1);
    int b = fibo(n-2);
    return a + b;
}

int main(){
    int n;
    cin >> n;
    cout << numBT_3(n);
    //cout << minCount_3(1000);
    //cout << stairs(4);
    //cout << minSteps3(7);
    //cout << fibo_3(7);
}