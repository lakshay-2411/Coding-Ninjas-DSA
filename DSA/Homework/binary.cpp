#include  <iostream>
using namespace std;

int search(int arr[],int low,int high,int elem){
    while(low<=high){
        int mid =  (low + high)/2;
        if(arr[mid] == elem) return mid;
        if(elem > arr[mid]) low = mid + 1;
        else high = mid-1;
    }
    return -1;
}

int main(){
    int n,arr[100];
    cout <<"Enter the size of array : " << endl;
    cin >> n;
    cout << "Enter array elements : " << endl;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int elem;
    cout << "Enter the element you want to search for : " << endl;
    cin >> elem;
    int result = search(arr,0,n-1,elem);
    if(result == -1)
    cout << "Not found " << endl;
    else 
    cout << "Index of the number is " << result;
}