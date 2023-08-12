#include <iostream>
using namespace std;

int allindex(int arr[],int size,int x, int output[]){
    if(size<=0){
        return 0;
    }
    int smallAns = allindex(arr,size-1,x,output);
    if(arr[size-1]==x){
        output[smallAns] = size-1;
        return smallAns+1;
    }else{
        return smallAns;
    }
    
}

int main(){
    int arr[200],n,x;
    cout << "Enter the size of array " << endl;
    cin >> n;
    cout << "Enter array elements " << endl;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << "Enter the element you want to search " << endl;
    cin >> x;
    int *output = new int[n];
    int res = allindex(arr,n,x,output);
    for(int i=0;i<res;i++){
        cout << output[i] << " ";
    }
    delete [] output;
}