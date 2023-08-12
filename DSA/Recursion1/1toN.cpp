#include <iostream>
using namespace std;

void print(int n){
    if(n>1){
        print(n-1);
    }
    cout << n << " ";
}






//FOR printing numbers from N to 1
/*
void print(int n){
    cout << n << " ";
    if(n==1){
        return;
    }
    return print(n-1);

}
*/

int main(){
    int n;
    cout << "Enter n" << endl;
    cin >> n;
    print(n);
}