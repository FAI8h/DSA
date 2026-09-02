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
    }
    cout << "NULL" << endl;
}

Node *partitionList(Node *head, int x){
    Node sDummy(-1);
    Node lDummy(-1);

    Node *d1 = &sDummy;
    Node *d2 = &lDummy;


    while(head != NULL){
        if(head->val < x){
            d1->next = head;
            d1 = d1->next;
            head = head->next;
        }else{
            d2->next = head;
            d2 = d2->next;
            head = head->next;
        }
    }

    d1->next = lDummy.next;
    d2->next = NULL;

    return sDummy.next;
}

int main () {
    List l;

    l.push_back(1);
    l.push_back(4);
    l.push_back(3);
    l.push_back(2);
    l.push_back(5);
    l.push_back(2);

    printLL(l.head);
    printLL(partitionList(l.head, 3));
    return 0;
}
