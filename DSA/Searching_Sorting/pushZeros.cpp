#include <iostream>
using namespace std;

void pushZeros(int arr[],int n){
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i] != 0){
        swap(arr[j],arr[i]);
        j++;
        }
    }
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
    pushZeros(arr,n);

    cout << "Array after sorting is ";
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    
    return 0;
}