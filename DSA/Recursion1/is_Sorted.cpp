#include <iostream>
using namespace std;

bool sorted(int arr[],int size){
    if(size == 0 || size == 1){
        return true;
    }
    bool smallSorted = sorted(arr + 1, size - 1);
    if(!smallSorted){
        return false;
    }
    if(arr[0] > arr[1]){
        return false;
    }else{
        return true;
    }
}





         /// METHOD 2 ///   
         /*
bool sorted(int arr[],int size){
    if(size == 0 || size == 1){
        return true;
    }
    if(arr[0] > arr[1]){
        return false;
    }
    bool smallSorted = sorted(arr+1,size-1);
    return smallSorted;
}
*/




         /// METHOD 1 ///  
         /* 
bool sorted(int arr[],int size){
    if(size == 0 || size == 1){
        return true;
    }
    if(arr[0] > arr[1]){
        return false;
    }
    sorted(arr+1,size-1);
}
*/



int main(){
    int arr[100],n;
    cout << "Enter size of Array " << endl;
    cin >> n;

    cout << "Enter array elements " << endl;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int result = sorted(arr,n);
    if(result==0){
    cout << "Array is not sorted " << endl;
    }else
    cout << "Array is sorted " << endl;
}