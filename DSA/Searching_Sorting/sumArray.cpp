#include <iostream>
using namespace std;

int sumArray(int arr1[],int arr2[],int n,int m){
    int arr3[10^4];
    int k=n,carry=0;
    int i=n-1,j=m-1;
    while(k>=0){
        if(i>=0 && j>=0){
        int result =arr1[i]+arr2[j]+carry;
        arr3[k--]=result%10;
        carry=result/10;
        i--;
        j--;
        } else if(j<0 && i>=0){
            int result = arr1[i]+carry;
            arr3[k--]=result%10;
            carry=result/10;
            i--;
        } else if(i<0 && j>=0){
            int result = arr2[j]+carry;
            arr3[k--]=result%10;
            carry=result/10;
            j--;
        } else {
            arr3[k--]=carry;
        }
    }
    return arr3[k];
}
int finalsum(int arr1[], int arr2[], int n, int m)
{
	if (n >= m)
		return sumArray(arr1, arr2, n, m);

	else
		return sumArray(arr2, arr1, m, n);
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
        sumArray(arr1,arr2,n,m);

	cout << "Array after addition is " <<endl;
	for (int i=0; i < n+1; i++)
		cout << arr3[i] << " ";

	return 0;
}

