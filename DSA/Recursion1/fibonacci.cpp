#include <iostream>
using namespace std;

int fibo(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    int smallOutput1 = fibo(n-1);
    int smallOutput2 = fibo(n-2);
    return smallOutput1 + smallOutput2;
}

int main(){
    int n;
    cout << "Enter the nth term you want to find : " ;
    cin >> n;
    cout << fibo(n) << endl;
} 