#include <iostream>
using namespace std;

int sum(int arr[],int size){
    if(size<=0){
        return 0;
    }
    return (sum(arr,size-1) + arr[size-1]);
}




           /// METHOD 1 ///
           /* 
int sum(int arr[],int size){
    if(size==0){
        return 0;
    }
    if(size==1){
        return arr[0];
    }
    int ans = arr[0] + sum(arr + 1,size - 1);
    return ans;
}
*/

int main(){
    int arr[200],n;
    cout << "Enter size of array " << endl;
    cin >> n;
    cout << "Enter array elements " << endl;\
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << sum(arr,n) << endl;
}