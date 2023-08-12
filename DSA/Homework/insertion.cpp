#include <iostream>
using namespace std;

void insertion(int  arr[],int size,int pos,int elem){
    for (int i = size; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = elem;
    size++;
    cout << "Array after insertion: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    
}

int main(){
    int n,pos,elem;
    cout << "Entet size of array : ";
    cin >> n;
    int arr[100];
    cout << "Enter array elements : ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << "Enter the position where the element should be inserted: ";
    cin >> pos;
    cout << "Enter the element to be inserted: ";
    cin >> elem;
    insertion(arr,n,pos,elem);
}