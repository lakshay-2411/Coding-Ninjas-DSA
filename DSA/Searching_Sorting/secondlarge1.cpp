#include <iostream>
using namespace std;

int second(int arr[],int n){
    int largest=0,secondl=-1;
    for(int i=0;i<n; i++){
        if(arr[i] > arr[largest]){
            largest = i;
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i] != arr[largest]){
            if(secondl == -1)
            secondl=i;
            else if(arr[i]>arr[secondl])
            secondl=i;
        }
    }
    return secondl;
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
        int secondla = second(arr,n);
        if(secondla==-1)
        cout << "no second largest ";
        else
        cout << "second largest is " << arr[secondla];
    return 0;
}
