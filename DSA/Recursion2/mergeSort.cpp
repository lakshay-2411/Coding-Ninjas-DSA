#include <iostream>
using namespace std;

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
}

void merge_Sort(int arr[],int si,int ei,int mid){
    int i=si,j=mid+1,k=si,temp[ei+1];
    while(i<=mid && j<=ei){
        if(arr[i] < arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=ei){
        temp[k++] = arr[j++];
    }
    for(i=si;i<k;i++){
        arr[i] = temp[i];
    }
}

void merge(int arr[],int si,int ei){
    if(si<ei){
        int mid = (si+ei)/2;
        merge(arr,si,mid);
        merge(arr,mid+1,ei);

        merge_Sort(arr,si,ei,mid);
    }
}

int main(){
    int arr[200];
    int n;
    cout << "Enter size of array " << endl;
    cin >> n;
    cout << "Enter array elements " << endl;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    merge(arr,0,n-1);
    
    printArray(arr,n);
}