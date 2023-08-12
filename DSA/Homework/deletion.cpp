#include <iostream>
#include <climits>
using namespace std;

void deletion(int arr[],int size,int elem){
    int index=INT_MIN;
    for (int i = 0; i < size; i++) {
        if (arr[i] == elem) {
            index = i;
            break;
        }
    }

    if (index == INT_MIN) {
        cout << "Element not found in the array." << endl;
    } else {
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        cout << "Array after deletion: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
    }
}

int main(){
    int n,elem;
    cout << "Entet size of array : ";
    cin >> n;
    int arr[100];
    cout << "Enter array elements : ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << "Enter the value of the element to be deleted: ";
    cin >> elem;
    deletion(arr,n,elem);
}