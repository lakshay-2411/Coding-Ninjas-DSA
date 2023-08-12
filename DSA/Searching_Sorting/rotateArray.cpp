#include <iostream>
using namespace std;

int main(){
            int n;
    int arr[10^4];
    cout << "Enter the size of array ";
    cin >> n;
    cout << "Enter array elements ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int d;
    cout << "Enter from where you want to rotate ";
    cin >> d;
    for(int i=d;i<n;i++){
        cout << arr[i] << " ";
    }
    for(int i=0;i<d;i++){
        cout << arr[i] << " ";
    }
}