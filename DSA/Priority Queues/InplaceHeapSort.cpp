//Space Complexity : O(n)
#include <iostream>
using namespace std;

void inplaceHeapSort(int input[],int n){
    // Build the heap in input array

    for(int i=1;i<n;i++){

        int childIndex =  i;

        while(childIndex > 0){
            int parentIndex = (childIndex - 1)/2;

            if(input[childIndex] < input[parentIndex]){
                int temp = input[childIndex];
                input[childIndex] = input[parentIndex];
                input[parentIndex] = temp;
            }else{
                break;
            }
            childIndex = parentIndex;
        }
    }

    // Remove elements

    int size = n;

    while(size > 1){
        int ans = input[0];
        input[0] = input[size-1];
        input[size-1] = ans;

        size--;

        //down - heapify
        int parentIndex = 0;
        int leftChild = 2 * parentIndex + 1;
        int rightChild = 2 * parentIndex + 2;

        while(leftChild < size){
            int minIndex = parentIndex;
            if(input[minIndex] > input[leftChild]){
                minIndex = leftChild;
            }
            if(rightChild < size && input[minIndex] > input[rightChild]){
                minIndex = rightChild;
            }
            if(minIndex == parentIndex){
                break;
            }
            int temp = input[minIndex];
            input[minIndex] = input[parentIndex];
            input[parentIndex] = temp;

            parentIndex = minIndex;
            leftChild = 2 * parentIndex + 1;
            rightChild = 2 * parentIndex + 2;
        }
    }
}

int main(){
    int input[] = {5,1,2,0,8};
    inplaceHeapSort(input,5);
    for(int i=0;i<5;i++){
        cout << input[i] << " ";
    }
}