        /// CHECK ARRAY ROTATION ///
        int checkRotation(int *arr,int n){
    for(int i=0;i<n-1;i++){
        if(arr[i] > arr[i+1]){
            return (i+1);
            break;
        }
    }
    return 0;
}

        /// ROTATE ARRAY BY LEFT///
        void rotateArr(int arr[], int d, int n){
        // code here
        int z = d%n;
        int temp[z];
        for(int i=0;i<z;i++){
            temp[i] = arr[i];
        }
        for(int i=0;i<n-z;i++){
        arr[i] = arr[i+z];
        }
        for(int i=n-z;i<n;i++){
            arr[i] = temp[i-n+z];
        }
    }

        /// FIND UNIQUE ///
        int findUnique(int *arr, int n)
{
    int num = arr[0];
    for (int i = 1; i < n; i++)
        num = num ^ arr[i];
    return num;
}

        /// FIND DUPLICATE ///




        /// ARRAY INTERSECTION ///
void intersection(int *input1, int *input2, int size1, int size2)
{
    //Write your code here

    //sort(input1,input1+size1);
    //sort(input2,input2+size2);
    int i=0,j=0;
    while(i<size1 && j<size2){
        if(input1[i] == input2[j]){
            //cout << input1[i] << " ";
            i++;
            j++;
        } else if(input1[i] < input2[j]){
            i++;
        } else{
            j++;
        }
    }
}


        /// PAIR SUM ///




        /// TRIPLET SUM ///




        
        /// ROTATE ARRAY BY RIGHT ///
        void rotateArray(int *arr,int k,int size){
    int z = k%size;
    int *temp = new int[z];
    for(int i=0;i<z;i++){
        temp[i] = arr[size-z+i];
    }
    for(int i=size-1;i>=z;i--){
        arr[i] = arr[i-z];
    }
    for(int i=0;i<z;i++){
        arr[i] = temp[i];
    }
    delete [] temp;
}