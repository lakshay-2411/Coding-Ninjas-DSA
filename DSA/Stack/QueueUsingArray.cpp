#include <iostream>
#include <climits>
using namespace std;

template <typename T>
class Queue{
    T *data;
    int nextIndex;
    int frontIndex;
    int size;
    int capacity;

    public:
    Queue(int totalSize){
        data = new T[totalSize];
        nextIndex = 0;
        frontIndex = -1;
        size = 0;
        capacity = totalSize;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
    T front(){
        if(isEmpty()){
            cout << "Queue is empty " << endl;
            return 0;
        }   
        return data[frontIndex];
    }
    void enqueue(T element){
        if(size == capacity){
            cout << "Queue is Full " << endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex+1)%capacity;
        if(frontIndex == -1){
            frontIndex = 0;
        }
        size++;
    }
    T dequeue(){
        if(isEmpty()){
            cout << "Queue is Empty " << endl;
            return 0;
        }
        T ans = data[frontIndex];
        frontIndex = (frontIndex+1)%capacity;
        size--;
        if(size == 0){
            frontIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }

};

int main(){
    Queue<int> q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.getSize() << endl;
    cout << q.isEmpty() << endl;
}