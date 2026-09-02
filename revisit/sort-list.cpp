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

Node *merge(Node *left, Node *right){
    Node dummy(-1);
    Node *p = &dummy;

    while(left && right){
        if(left->val <= right->val){
            p->next = left;
            left = left->next;
        }else{
            p->next = right;
            right = right->next;
        }
        p = p->next;
    }

    p->next = left ? left : right;

    return dummy.next;
};

Node *sortLL(Node *head){
    if(head == NULL || head->next == NULL) return head;
    
    Node *slow = head;
    Node *fast = head->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *rightHalf = slow->next;
    slow->next = NULL;

    Node *left = sortLL(head);
    Node *right = sortLL(rightHalf);

    Node *newHead = merge(left, right);

    return newHead;
}

int main () {
    List l;
    l.push_back(1);
    l.push_back(3);
    l.push_back(9);
    l.push_back(4);
    l.push_back(0);
    printLL(l.head);
    
    Node *newHead = sortLL(l.head);
    printLL(newHead);


    return 0;
}