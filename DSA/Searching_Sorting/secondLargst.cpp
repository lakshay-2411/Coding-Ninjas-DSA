#include <iostream>
using namespace std;

int secondLargest(int arr[],int n){
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
        for (int i = n - 2; i >= 0; i--) {
        // if the element is not equal to largest element
        if (arr[i] != arr[n - 1]) {
          //  cout << arr[i];
            return arr[i];
        }
    }
    cout << "-1";

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
        secondLargest(arr,n);

   // cout << "Second largest in array is ";
    //if(arr[n-1] != arr[n-2])
      //  cout << arr[n-2] << " ";
    return 0;

}
