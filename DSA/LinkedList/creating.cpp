#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        next = NULL;
    }
};

Node* takeInput_Better(){
    int data;
    cin >> data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data != -1){
        Node* newNode = new Node(data);
        if(head == NULL){
            head =  newNode;
            tail = newNode;
        } else{
            tail->next = newNode; 
            tail = tail->next; 
            //OR
            //tail = newNode     
        }
        cin >> data;
    }
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

/*
int main(){
    // statically making the nodes
    Node n1(1);
    Node* head = &n1;
    Node n2(2);
    n1.next = &n2;
    // dynamically making the nodes
    Node *n3 = new Node(10);
    Node* head = n3;
    Node *n4 = new Node(20);
    n3->next = n4;         //not using & but only n4 bcz this is a pointer 

    cout << head->data;
    cout << endl;
    cout << head->next->data;
    //cout << n1.data << " " << n2.data << endl;
}
*/