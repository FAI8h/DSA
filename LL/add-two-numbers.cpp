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

Node *addTwoList(Node *l1, Node *l2){
    Node *d1 = l1;
    Node *d2 = l2;
    Node newList(-1);
    Node *dummy = &newList;
    int carry = 0;
    int currSum = 0;
    while (d1 && d2){
        currSum = d1->val + d2->val + carry;
        Node *newNode = new Node(currSum % 10);
        dummy->next = newNode;
        dummy = dummy->next;

        carry = currSum / 10;

        d1 = d1->next;
        d2 = d2->next;
    }

    if(!d1){
        while(d2 != NULL){
            currSum = d2->val + carry;
            Node *newNode = new Node(currSum % 10);
            dummy->next = newNode;
            dummy = dummy->next;

            carry = currSum / 10;

            d2 = d2->next;
        }
    }else{
        while(d1 != NULL){
            currSum = d1->val + carry;
            Node *newNode = new Node(currSum % 10);
            dummy->next = newNode;
            dummy = dummy->next;

            carry = currSum / 10;

            d1 = d1->next;
        }
    }

    if(carry > 0){
        Node *newNode = new Node(carry);
        dummy->next = newNode;
    }

    return newList.next;
}

int main(){
    List l1;
    l1.push_back(2);
    l1.push_back(4);
    l1.push_back(3);

    List l2;
    l2.push_back(5);
    l2.push_back(6);
    l2.push_back(4);

    printLL(l1.head);
    printLL(l2.head);

    Node *h = addTwoList(l1.head, l2.head);

    printLL(h);
    return 0;
}