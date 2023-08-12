#include <iostream>
using namespace std;
#include "creating.cpp"

class LinkedList{
    public:
//---------------------------FOR DELETING(ITERATIVELY)---------------------------------------------
    Node* delete_elem(Node* head,int pos){
    if(head == NULL){
        return head;;
    }    
    int count = 0;
    Node* temp = head;
    if(pos == 0){
        head = temp->next;
        delete temp;
        return head;
    }
    while(temp != NULL && count < pos-1){
        temp = temp->next;
        count++;
    }
    if(temp == NULL || temp->next == NULL){
        return head;
    }
    Node* a = temp->next;
    Node* b = a->next;
    temp->next = b;
    delete a;
    return head;
}

//------------------------FOR DELETING(RECURSIVELY)------------------------------------------------
Node* delete_element(Node* head,int i){
    if(head == NULL){
        return NULL;
    }
    if(i == 0){
        return head->next;
    }
    head->next = delete_element(head->next,i-1);
    return head;
}

//------------------------FOR INSERTING(ITERATIVELY)------------------------------------------------
Node* insert_elem(Node* head,int pos,int data){
    Node* newNode = new Node(data);
    int count = 0;
    Node* temp = head;
    if(pos == 0){
        newNode->next = head;
        head = newNode;
        return head;
    }
    while(temp != NULL && count < pos-1){
        temp = temp->next;
        count++;
    }
    if(temp != NULL){
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

//---------------------------FOR INSERTING(RECURSIVELY)---------------------------------------------
Node* insert_element(Node* head,int i,int data){
    if(head == NULL){
        if(i == 0){
            Node* newNode = new Node(data);
            return newNode;
        }
        return NULL;
    }
    if(i == 0){
        Node* newNode = new Node(data);
        newNode->next = head;
        return newNode;
    }
    head->next = insert_element(head->next,i-1,data);
    return head;
}



};

int main(){
    Node* head = takeInput_Better();
    print(head);
    int pos,data;
    cin >> pos >> data;
    LinkedList a;
    head = a.insert_element(head,pos,data);
    //head = a.insert_elem(head,pos,data);
    print(head);
}