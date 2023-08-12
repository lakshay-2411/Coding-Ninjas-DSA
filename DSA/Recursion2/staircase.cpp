#include <iostream>
using namespace std;

int countSteps(int n){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    return countSteps(n-1) + countSteps(n-2);
}

int main(){
    int n;
    cout << "Enter number of steps " << endl;
    cin >> n;
    cout << "Number of possible ways are " << countSteps(n) << endl;
}