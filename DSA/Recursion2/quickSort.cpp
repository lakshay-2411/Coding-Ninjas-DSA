#include <iostream>
using namespace std;

int partition(int arr[],int si,int ei){
    int pivot = arr[si];
    int i=si;
    for(int j=si+1;j<=ei;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[si],arr[i]);
    return i;
}

void quickSort(int arr[],int si,int ei){
    if(si<ei){
        int pi = partition(arr,si,ei);
        quickSort(arr,si,pi-1);
        quickSort(arr,pi+1,ei);
    }
}

int main(){
    int n;
    cout << "Enter size of array " << endl;
    cin >> n;
    int arr[n+1];
    cout << "Enter array elements " << endl;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout << arr[i] <<" ";
    }
}