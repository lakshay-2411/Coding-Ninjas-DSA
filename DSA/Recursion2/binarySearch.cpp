#include <iostream>
using namespace std;

int binary(int arr[],int x,int low,int high){
    if(high<0){
        return -1;
    }
    int mid = (low+high)/2;
    if(arr[mid]==x) return mid;
    if(arr[mid]<x) return binary(arr,x,mid+1,high);
    else return binary(arr,x,low,mid-1);
}

int main(){
    int arr[] = {2,3,4,5,6,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 5;
    int result = binary(arr,x,0,n-1);
    if(result ==-1){
        cout << "Not found";
    }else{
        cout << "Index of number is " << result;
    }
}