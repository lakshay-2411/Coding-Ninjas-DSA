//#include "MinHeap.h"

#include "MaxHeap.h"

int main(){
    MaxHeap pq;
    pq.insert(60);
    pq.insert(70);
    pq.insert(80);
    pq.insert(90);
    pq.insert(100);
    pq.insert(75);
    pq.insert(71);

    cout << "Size : " << pq.getSize() << endl;

    cout << "Maximum Element is : " << pq.getMax() << endl;

    while(!pq.isEmpty()){
        cout << "Removed Element is : " << pq.removeMax() << endl;
    }
    cout << endl;








    /*
    PriorityQueue pq;
    pq.insert(100);
    pq.insert(10);
    pq.insert(15);
    pq.insert(4);
    pq.insert(17);
    pq.insert(21);
    pq.insert(67);

    cout << "Size : " << pq.getSize() << endl;

    cout << "Minimum Element is : " << pq.getMin() << endl;

    while(!pq.isEmpty()){
        cout << "Removed element is : " << pq.removeMin() << endl; 
    }
    cout << endl;


    */
}