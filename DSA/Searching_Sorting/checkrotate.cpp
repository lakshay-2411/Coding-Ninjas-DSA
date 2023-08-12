#include <iostream>
using namespace std;

int checkRotate(int arr[],int n){
    int i=0,j=i+1;
    while(i<n){
        if(arr[i]>arr[j]){
            return i+1;
        }
        i++;
        j++;
    }
    return 0;
}

int main(){
    int n;
    int arr[10^4];
    cout << "Enter the size of array ";
    cin >> n;
    cout << "Enter array elements ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << "The index from which rotation happens is " << checkRotate(arr,n);
}