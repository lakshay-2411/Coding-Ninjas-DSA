#include <iostream>
using namespace std;
#include "creating.cpp"

class Pair{
    public:
    Node* head;
    Node* tail;
};

class LinkedList{
    public:
//-------------------------------------FIND_A_NODE--------------------------------------------------

    int find(Node* head,int value){
    int count = 0;
    Node* temp = head;
    while(temp != NULL && temp->data != value){
        temp = temp->next;
        count++;
    }
    if(temp != NULL){
        return count;
    }else{
        return -1;
    }
}
//-------------------------------------LENGTH(RECURSIVELY)------------------------------------------

    int length(Node* head){
        int count = 0;
        if(head==NULL){
            return 0;
        }
        return 1 + length(head->next);
    }

//-----------------------------------APPENDLAST_NToFirst--------------------------------------------
Node* Append(Node* head,int n){
    if(n == 0 || head == NULL){
        return head;
    }
    Node* tail = head;
    Node* ptr = head;
    //int length = 1;
    while(tail->next != NULL){
        tail = tail->next;
        //length++;
    }
    int i = 1;
    while(i < length(head)-n){
        ptr = ptr->next;
        i++;
    }
    if(tail->next == NULL){
        return head;  
    } else{
        tail->next = head;
        head = ptr->next;
        ptr->next = NULL;
        return head;
    }
}

//-----------------------------------ELIMINATE_DUPLICATES-------------------------------------------
Node * eliminate(Node* head){
    Node* temp =  head;
    if(head == NULL){
        return head;
    }
    while(temp->next != NULL){
        if(temp->data == temp->next->data){
            temp->next = temp->next->next;
            //temp = temp->next;
        } else{
            temp = temp->next;
        }
    }
    return head;
}

//---------------------------------PRINT REVERSE LL------------------------------------------------
void reversePrint(Node* head){
    if(head == NULL){
        return;
    }
    reverse(head->next);
    cout << head-> data << " ";
}

//--------------------------------MID POINT OF LL---------------------------------------------------
Node* middle(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

//--------------------------------MERGE_2_SORTED_LL-------------------------------------------------
Node* merge(Node* h1,Node* h2){
    Node* fh = NULL;
    Node* ft = NULL;
    if(h1==NULL && h2 == NULL){
        return fh;
    }
    if(h1==NULL){
        return h2;
    }
    if(h2==NULL){
        return h1;
    }
    if(h1->data <= h2->data){
        fh = h1;
        ft = h1;
        h1 = h1->next;
    }else if(h1->data > h2->data){
        fh = h2;
        ft = h2;
        h2 = h2->next;
    }
    while(h1 != NULL && h2 != NULL){
        if(h1->data <= h2->data){
            ft->next = h1;
            ft = h1;
            h1= h1->next;
        } else if(h1->data > h2->data){
            ft->next = h2;
            ft = h2;
            h2 = h2->next;
        }
    }
    if(h1 == NULL && h2 != NULL){
        while(h2 != NULL){
            ft->next = h2;
            ft = h2;
            h2 =  h2->next;
        }
    } else if(h1 != NULL && h2 == NULL){
        while(h1 != NULL){
            ft->next = h1;
            ft = h1;
            h1 = h1->next;
        }
    }
    ft ->next = NULL;
    return fh;
}

//------------------------------------MERGE_SORT---------------------------------------------------
Node* mergeSort(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* mid = middle(head);
    Node* head1 = mid->next;
    mid->next =  NULL;
    head = mergeSort(head);
    head1 = mergeSort(head1);
    return merge(head,head1);
}

//------------------------------------REVERSE_LL_O(N^2)--------------------------------------------
Node* reverse(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* smallAns = reverse(head->next);
    Node* temp = smallAns;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return smallAns;
}

//-----------------------------------REVERSE_LL_O(N)-----------------------------------------------
Pair reverse_LL(Node* head){
    if(head == NULL || head->next == NULL){
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    Pair smallAns = reverse_LL(head->next);
    smallAns.tail->next = head;
    head->next = NULL;
    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;
    return ans;
}
Node* helper(Node* head){
    return reverse_LL(head).head;
}

//-------------------------------------REVERSE_BEST_O(N)------------------------------------------
Node* reverse_best(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* smallAns = reverse_best(head->next);
    Node* tail = head->next;
    tail->next = head;
    head->next = NULL;
    return smallAns;
}

//-----------------------------------REVERSE_LL_ITERATIVE----------------------------------------
Node* reverse_iterative(Node* head){
    Node* current = head;
    Node* nxt = NULL;
    Node* prev = NULL;
    while(current != NULL){
        nxt = current->next;
        current->next = prev;
        prev = current;
        current = nxt;
    }
    return prev;
}

//-------------------------------------EVEN_AFTER_ODD--------------------------------------------
Node* evenAfterOdd(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* oddH = NULL;
    Node* oddT = NULL;
    Node* evenH = NULL;
    Node* evenT = NULL;
    Node* temp = head;
    while(temp != NULL){
        if(temp->data%2 != 0){
            if(oddH == NULL){
                oddH = temp;
                oddT = temp;
            } else{
                oddT->next = temp;
                oddT = oddT->next;
            }
        }else{
            if(evenH == NULL){
                evenH = temp;
                evenT = temp;
            } else{
                evenT->next = temp;
                evenT = evenT->next;
            }
        }
        temp = temp->next;
    }
    if(oddT == NULL){
        return evenH;
    }
    oddT->next = evenH;
    if(evenT != NULL){
        evenT->next = NULL;
    }
    return oddH;
}

//---------------------------------
};

int main(){
    LinkedList a;
    Node* head = takeInput_Better();
    int value; cin >> value;
    a.find(head,value);
}