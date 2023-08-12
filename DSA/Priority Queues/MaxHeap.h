#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class MaxHeap{
    vector<int> pq;

    public:

    MaxHeap(){

    }

    bool isEmpty(){
        return pq.size() == 0;
    }

    int getSize(){
        return pq.size();
    }

    int getMax(){
        if(isEmpty()){
            return INT_MIN;
        }
        return pq[0];
    }

    void insert(int element){
        pq.push_back(element);

        int childIndex = pq.size()-1;

        while(childIndex > 0){
            int parentIndex = (childIndex - 1)/2;

            if(pq[childIndex] > pq[parentIndex]){
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }else{
                break;
            }
            childIndex = parentIndex;
        }
    }

    int removeMax(){
        if(isEmpty()){
            return INT_MIN;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();


        int parentIndex = 0;
        int leftChild = 2 * parentIndex + 1;
        int rightChild = 2 * parentIndex + 2;

        while(leftChild < pq.size()){
            int maxIndex = parentIndex;
            if(rightChild < pq.size() && pq[maxIndex] < pq[rightChild]){
                maxIndex = rightChild;
            }
            if(pq[maxIndex] < pq[leftChild]){
                maxIndex = leftChild;
            }
            if(maxIndex == parentIndex){
                break;
            }
            int temp = pq[maxIndex];
            pq[maxIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = maxIndex;
            leftChild = 2 * parentIndex + 1;
            rightChild = 2 * parentIndex + 2;
        }
        return ans;
    }
};