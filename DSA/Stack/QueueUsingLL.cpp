#include <iostream>
using namespace std;
template <typename T>
class Node{
    public:
    T data;
    Node<T>* next;
    Node(T data){
        this -> data = data;
        next = NULL;
    }
};
template <typename T>
class Queue{
    Node<T>* head;
    Node<T>* tail;
    int size;

    public:
    Queue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void enqueue(T element){
        Node<T>* newNode = new Node<T>(element);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return head == NULL;
    }
    T dequeue(){
        if(isEmpty()){
            cout << "Queue is Empty " << endl;
            return 0;
        }
        T ans = head -> data;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }
    T front(){
        if(isEmpty()){
            return 0;
        }
        return head -> data;
    }
};
int main(){
    Queue<char> q;

    q.enqueue(100);
    q.enqueue(101);
    q.enqueue(102);
    q.enqueue(103);
    q.enqueue(104);
    q.enqueue(105);

    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.getSize() << endl;
    cout << q.isEmpty() << endl;
}