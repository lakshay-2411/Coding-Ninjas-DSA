#include <iostream>
using namespace std;

int binary(int arr[],int x,int low,int high) {
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == x) return mid;
        if(arr[mid]<x) low = mid + 1;
        else high = mid-1;
    }
    return -1;
}
int main(){
    int arr[] = {2,3,4,76,87,98};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x=87;
    int result = binary(arr,x,0,n-1);
    if(result == -1)
    cout << "Not Found ";
    else 
    cout << "The index of number is " << result;






    /*
    int arr[10^4];
    int n;
    cout << "enter size of array " << endl;
    cin >> n;
    cout << "enter array elements " << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int x;
    cout << "enter the element to find " << endl;
    cin >> x;
    int result = binary(arr,x,0,n-1);
    if(result == -1)
    cout << "Not Found ";
    else 
    cout << "The index of number is " << result;
*/

}
