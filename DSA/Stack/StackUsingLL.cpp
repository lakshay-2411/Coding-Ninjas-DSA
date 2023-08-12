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
class Stack{
    Node<T>* head;
    int size;

    public:
    Stack(){
        head = NULL;
        size = 0;
    }
    void push(T data){
        Node<T>* newNode = new Node<T>(data);
        if(head == NULL){
            head = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
        size++;
    }
    T pop(){
        if(head == NULL){
            return 0;
        }
        T ans = head -> data;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }
    T top(){
        if(isEmpty()){
            return -1;
        }
        return head -> data;
    }
    bool isEmpty(){
        return head == NULL;
    }
    int getSize(){
        return size;
    }

};

int main(){
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << s.top() << endl;

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << s.getSize() << endl;

    cout << s.isEmpty() << endl;
}