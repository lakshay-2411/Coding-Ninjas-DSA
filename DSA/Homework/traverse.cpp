#include <iostream>
using namespace std;

void traverse(int arr[],int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int n;
    cout << "Entet size of array : ";
    cin >> n;
    int arr[100];
    cout << "Enter array elements : ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    traverse(arr,n);
}