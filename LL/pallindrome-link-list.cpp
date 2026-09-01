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


void printLL(Node* head){
    Node *curr = head;

    while(curr != NULL){
        cout << curr->val << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

bool isPallindrome(Node *head){
    Node dummy(-1);
    dummy.next = head;
    Node *d = &dummy;//* just behind slow to unlink

    Node *slow = head; //* slow will be the right half
    Node *fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    //* unlink the right half
    d->next = NULL;

    //* reverse the right half
    Node *curr = slow;//* taking slow as right half's head
    Node *next = NULL;
    Node *prev = NULL;//* this will be the head of the reversed list

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    Node *h1 = head; //* left half's head
    Node *h2 = prev; //* right half's head

    while(h1 && h2){
        if(h1->val != h2->val){
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    return true;
}

int main () {
    List l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(2);
    l.push_back(1);

    printLL(l.head);

    cout << isPallindrome(l.head) << endl;


    return 0;
}