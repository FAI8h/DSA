#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace  std;

class Node {
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

    List() : head{NULL}, tail{NULL} {};

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
    }; 
    cout << "NULL" <<endl; 
};

Node *reverseLL(Node *head){
    Node *curr = head;
    Node *next = NULL;
    Node *prev = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    return prev;
}

Node *mergeLL(Node *h1, Node *h2) {
    Node dummy(-1);
    Node *d = &dummy;

    Node *p1 = h1;
    Node *p2 = h2;

    while(p1 && p2){
        d->next = p1;
        d = d->next;
        p1 = p1->next;
        d->next = p2;
        d = d->next;
        p2 = p2->next;
    }

    d->next = p1 ? p1 : p2;

    return dummy.next;
};


Node *reorderList(Node *head){
    if(head == NULL || head->next == NULL) return head;
    Node dummy(-1);
    Node *d = &dummy;
    dummy.next = head;

    Node *slow = head;
    Node *fast = head;
    while(fast != NULL && fast->next != NULL){
        d = d->next;
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *rightHalf = d->next;
    d->next = NULL;
    
    Node *right = reverseLL(rightHalf);

    return mergeLL(head, right);
}


int main(){
    List l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);

    printLL(l.head);

    Node *newHead = reorderList(l.head);

    printLL(newHead);
    return 0;
}