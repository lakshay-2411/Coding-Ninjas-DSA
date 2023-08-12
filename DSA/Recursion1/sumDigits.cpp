#include <iostream>
using namespace std;

long int sumDigits(int n){
    if(n<=0){
        return 0;
    }
    return sumDigits(n/10) + n%10;
}

int main(){
    long int n;
    cout << "Enter the number " << endl;
    cin >> n;
    cout << sumDigits(n);
}