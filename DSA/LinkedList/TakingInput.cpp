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

// Time Complexity : O(N)

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

int count(Node* head){
    int count = 0;
    if(head == NULL){
        return 0;
    }
    Node* current = head;
    while(current != NULL){
        current = current->next;
        count++;
    }
    return count;
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
    int t;
    cout << "Enter Number of Test Cases: ";
    cin >> t;
    while(t--){
        cout << "Enter the numbers: ";
        Node* head = takeInput_Better();
        cout << "The Linked List is: ";
        print(head);
        cout << endl;
        cout << "The number of elements in Linked List are: ";
        cout << count(head); cout << endl;
    }
}
*/




/*   // Time Complexity : O(N^2)    NOT GOOD 
Node* takeInput(){
    int data;
    cin >> data;
    Node* head = NULL;
    while(data != -1){
        Node* newNode = new Node(data);
        if(head == NULL){
            head =  newNode;
        } else{
            Node *temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;       
        }
        cin >> data;
    }
    return head;
}
*/