#include <iostream>
using namespace std;

int sum(int* arr,int size){
    cout << sizeof(arr) << endl;    //This will give the size of pointer because arrays are passed as pointers in functions
    int ans = 0;
    for(int i=0;i<size;i++){
        ans =+ arr[i];
    }
    return ans;
}

int main(){
    int arr[10];
    cout << sizeof(arr) << endl;   //This will give size of array
   // cout << sum(arr,10) << endl;

    //We can also pass the part of arrays and then have to reduce the size of array
    cout << sum(arr + 3,7) << endl;
}