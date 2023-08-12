#include <iostream>
using namespace std;

bool check(int arr[],int size,int x){
    if(size<=0){
        return false;
    }
    if(arr[0]==x){
        return true;
    } else{
        check(arr+1,size-1,x);
    }
}

int main(){
    int arr[200],n,x;
    cout << "Enter size of  array " << endl;
    cin >> n;
    cout << "Enter array elements " << endl;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << "Enter the element you want to search " << endl;
    cin >> x;
    int result = check(arr,n,x);
    if(result==1){
        cout << "True";
    }else{
        cout << "False";
    }
}