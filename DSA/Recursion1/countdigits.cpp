#include <iostream>
using namespace std;

int count(int n){
    if(n/10==0){
        return 1;
    }
    int ans = 1 + count(n/10);
    return ans;
}

int main(){
    int n;
    cout  << "Enter the number" << endl;
    cin >> n;
    cout << count(n) << endl;
    
}