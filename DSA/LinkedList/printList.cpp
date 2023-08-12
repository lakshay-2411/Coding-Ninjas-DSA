#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

/*

void printIth(Node* head,int pos){
    Node* temp = head;
    int count= 0;
    while(count != pos){
        temp = temp->next;
        count++;
    }
    cout << temp->data;   
}

*/

// create temp to avoid losing the head
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
// this will print bcz we have not changed head in first loop but don't print list using this
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

int main(){
    Node n1(10);
    Node* head = &n1;

    Node n2(20);
    Node n3(30);
    Node n4(40);
    Node n5(50);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    print(head);
    //print(head);
}