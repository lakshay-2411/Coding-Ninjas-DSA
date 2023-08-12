#include <iostream>
using namespace std;

void sorting(int arr[],int n){
    //find minimum in the array
    for(int i=0;i<n-1;i++){
        int min=arr[i],minindex=i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<min){
                min = arr[j];
                minindex = j;
            }
        }
    //swap
    int temp = arr[i];
    arr[i] = min;
    arr[minindex] = temp;
    }
}

int main(){
    int arr[10^4];
    int n;
    cout << "Enter size of array ";
    cin >> n;
    cout << "Enter array elements ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
sorting(arr,n);
cout << "Array after sorting is ";
for(int i=0; i<n; i++){
cout << arr[i] << " ";
}
}
    