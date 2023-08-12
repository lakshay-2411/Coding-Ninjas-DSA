#include <iostream>
using namespace std;

void insertion(int arr[],int n){
    for(int i=1;i<n;i++){
        int current=arr[i];
        int j;
        for(j=i-1;j>=0;j--){
            if(current<arr[j]){
                arr[j+1]=arr[j];
            }
            else {
                break;
            }
        }
        arr[j+1]=current;
    }
}

int main(){
    int arr[] = {2,6,7,2,1,5,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x=87;
    insertion(arr,n);
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
insertion(arr,n);
cout << "Array after sorting is ";
for(int i=0; i<n; i++){
    cout << arr[i] << " ";
    }
    */
}