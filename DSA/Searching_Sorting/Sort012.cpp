#include <iostream>
using namespace std;

void Sorting(int arr[],int n){
    int i=0,k=0,j=n-1;
    while(k<=j){
        if(arr[k]==0){
            swap(arr[i],arr[k]);
            i++;
            k++;
        } else if(arr[k]==1){
            k++;
        } else if(arr[k]==2){
            swap(arr[j],arr[k]);
            j--;
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
    Sorting(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}