#include <iostream>
using namespace std;

int product(int m,int n){
    if(m==0 || n==0){
        return 0;
    }
    return m + product(m,n-1);
}

int main(){
    int num1,num2;
    cout << "Enter number 1 " << endl;
    cin >> num1;
    cout << "Enter number 2 " << endl;
    cin >> num2;
    cout << product(num1,num2);
}