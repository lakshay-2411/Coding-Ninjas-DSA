#include <iostream>
using namespace std;

int factorial(int n){
    //first check the base case
    if(n==0){
        return 1;
    }
    //now assume that it will work for (n-1) acc to PMI
    int smallOutput = factorial(n-1);
    // we have to prove it for n
    int output = n * smallOutput;
    return output;
}

int main(){
    int n;
    cin >> n;
    cout << factorial (n) << endl;
}