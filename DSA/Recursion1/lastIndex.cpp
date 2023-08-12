#include <iostream>
using namespace std;

int find(int arr[],int size,int x){
    if(size<=0){
        return -1;
    }
    int ans = find(arr+1,size-1,x);
    if(ans==-1){
        if(arr[0]==x){
            return 0;
        }else{
            return -1;
        }
    } else{
        return 1 + ans;
    }
}











/*
int find(int arr[],int idx,int x){
    if(idx<=0){
        return -1;
    }
    if(arr[idx]==x){
        return idx;
    }
    find(arr,idx-1,x);
} 
*/







int main(){
    int arr[100],n,x;
    cout << "Enter size of array " << endl;
    cin >> n;
    cout << "Enter array elements " << endl;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << "Enter the element you want to search " << endl;
    cin >> x;
    cout << find(arr,n-1,x);
}