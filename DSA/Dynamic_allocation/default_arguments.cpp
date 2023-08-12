#include <iostream>
using namespace std;
//The main use of this is that we can make our arguments optional that if someone will give value to it then we'll take that otherwise  we'll take the default value

//We can give the default values to the rightmost element only and then come to left of rightmost and not to the middle one

int sum(int a[], int size, int si=0){         //If we declare si = 0 here then it will take 0 by default if any value is not given during function calling
    //si = starting index
    int ans = 0;
    for(int i=si; i<size; i++){
        ans += a[i];
    }
    return ans;
}

int sum(int a, int b, int c=0, int d=0){        //We can make both of these zero also and even three of them also 
    return a + b + c + d;                       //It can make sum of 2,3 or 4 integers
}

int main(){
    int a[20];
    //input code for a
    for(int i=0;i<20;i++){
        cin >> a[i];
    }

    cout << sum(a,20) << endl;        //We don't want to give that zero if we want the sum of whole array

    //For second SUM function



}
