#include <iostream>
#include <algorithm>
using namespace std;

void merge(int arr1[],int n,int arr2[],int m,int arr3[]){
    int i=0,j=0,k=0;
    while(i<n && j<m){
        if(arr1[i]<arr2[j])
            arr3[k++]=arr1[i++];
            else
            arr3[k++]=arr2[j++];
    }
    while(i<n){
        arr3[k++]=arr1[i++];
    }
    while(j<m){
        arr3[k++]=arr2[j++];
    }
    sort(arr3,arr3 + (n+m));
}

int main()
{
    int n,m;
    cout << "Enter size of array 1 ";
    cin >> n;
    int arr1[n];
    cout << "Enter array elements ";
    for(int i=0; i<n; i++){
        cin >> arr1[i];
    }
    cout << "Enter size of array 2 ";
    cin >>m;
    int arr2[m];
    cout << "Enter array elements ";
    for(int i=0; i<m; i++){
        cin >> arr2[i];
    }
	int arr3[n+m];
	merge(arr1, n, arr2, m,arr3);

	cout << "Array after merging" <<endl;
	for (int i=0; i < n+m; i++)
		cout << arr3[i] << " ";

	return 0;
}
