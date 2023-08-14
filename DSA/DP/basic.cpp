#include <iostream>
#include <climits>
using namespace std;

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

//Method 2-----------------MEMORIZATION(Top to Bottom Approach)--------------Time Complexity : O(N)
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

//Method 2-----------------MEMORIZATION(Top to Bottom Approach)---------------Time Complexity : O(N)
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
    cout << minSteps3(7);
    //cout << fibo_3(7);
}