#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue{
    vector<int> pq;

    public:

    PriorityQueue(){

    }

    bool isEmpty(){
        return pq.size() == 0;
    }

        //Return the size of priority queue:- number of elements present
    int getSize(){
        return pq.size();
    }

    int getMin(){
        if(isEmpty()){
            return 0;
        }
        return pq[0];
    }

    void insert(int element){
        pq.push_back(element);

        //up-heapify

        int childIndex =  pq.size() - 1;

        while(childIndex > 0){
            int parentIndex = (childIndex - 1)/2;

            if(pq[childIndex] < pq[parentIndex]){
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }else{
                break;
            }
            childIndex = parentIndex;
        }
    }

    int removeMin(){
        if(isEmpty()){
            return 0;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();

        //down - heapify
        int parentIndex = 0;
        int leftChild = 2 * parentIndex + 1;
        int rightChild = 2 * parentIndex + 2;

        while(leftChild < pq.size()){
            int minIndex = parentIndex;
            if(rightChild < pq.size() && pq[minIndex] > pq[rightChild]){
                minIndex = rightChild;
            }
            if(pq[minIndex] > pq[leftChild]){
                minIndex = leftChild;
            }
            if(minIndex == parentIndex){
                break;
            }
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            leftChild = 2 * parentIndex + 1;
            rightChild = 2 * parentIndex + 2;
        }
        return ans;
    }
};
