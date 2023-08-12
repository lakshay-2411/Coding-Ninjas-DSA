#include <iostream>
using namespace std;

int count(int n){
    if(n==0){
        return 0;
    }
    int ans = count(n/10);
    if(n%10==0){
        ans = ans + 1;
    }
    return ans;
}

int main(){
    long int n;
    cout << "Enter the number " << endl;
    cin >> n;
    cout << count(n) << endl;
}