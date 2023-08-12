#include <iostream>
using namespace std;

void bubble(int arr[],int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n;j++){
            if(arr[j]<arr[i]){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        else
        continue;
        }
    }
}

int main(){
    int arr[] = {0,7,1,4,9,2,5,3,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubble(arr,n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }










    /*
    int arr[10^4];
    int n;
    cout << "Enter size of array ";
    cin >> n;
    cout << "Enter array elements ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    bubble(arr,n);
    cout << "Array after sorting is ";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    */
}
