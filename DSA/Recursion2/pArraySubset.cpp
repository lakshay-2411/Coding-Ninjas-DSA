#include <iostream>
using namespace std;

void helper(int arr[],int n,int output[],int m){
    if(n==0){
        for(int i=0;i<m;i++){
            cout << output[i] << " ";
        }
        cout << endl;
        return;    
    }
    //if we not include the element
    helper(arr+1,n-1,output,m);
    //if we include the first in the output
    int newOutput[1000];
    for(int j=0;j<m;j++){
        newOutput[j] = output[j];
    } 
    newOutput[m] = arr[0];
    helper(arr+1,n-1,newOutput,m+1);
}

void printSubset(int arr[],int n){
    int output[1000];
    helper(arr,n,output,0);
}

int main(){
    int n;
    cout << "Enter size of the array " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter array elements " << endl;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    printSubset(arr,n);
}