#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace  std;

class Node{
public:
    int val;
    Node *next;
    Node(int val){
        this->val = val;
        next = NULL;
    }
};

class List{
public:
    Node *head;
    Node *tail;

    List(){
        head = tail = NULL;
    }

    void push_back(int val){
        Node *newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
            return;
        }else{
            tail->next = newNode;
            tail = newNode;
            return;
        }
    }
};

void printLL(Node *head){
    Node *curr = head;

    while(curr != NULL){
        cout << curr->val << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}


Node *mergeLL(Node *list1, Node *list2){
    Node dummy(-1);
    Node *dtail = &dummy;

    while(list1 && list2){
        if(list1->val <= list2->val){
            dtail->next = list1;
            list1 = list1->next;
        }else{
            dtail->next = list2;
            list2 = list2->next;
        }

        dtail = dtail->next;
    }

    dtail->next = list1 ? list1 : list2;

    return dummy.next;
}

Node* sortLL(Node* head){
    if(head == NULL || head->next == NULL) return head;
    
    Node *slow = head; //* this will be mid

    //? why does fast have ahead start
    /*
    * slow needs to land on the LAST node of the
    * LEFT half — not the first node of the right.
    * Give fast a head start so slow stops one early.
    */
    Node *fast = head->next;


    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *right = slow->next;
    slow->next = NULL;

    //* left half
    Node *left = sortLL(head);

    //* right half
    Node *rightSorted = sortLL(right);

    return mergeLL(left, rightSorted);

}

int main () {

    List l;
    l.push_back(4);
    l.push_back(2);
    l.push_back(1);
    l.push_back(3);

    printLL(l.head);

    Node *newHead = sortLL(l.head);

    printLL(newHead);

    return 0;
}