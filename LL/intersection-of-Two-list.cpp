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
    cout << "NULL"<< endl;
}

void createIntersection(Node* list1, Node* list2){
    Node *p1 = list1;
    Node *p2 = list2;
    
    while (p2->next != NULL){
        p1 = p1->next;
        p2 = p2->next;
    }

    p2->next = p1->next->next;
    return;
}

Node *getIntersectionNode(Node* list1, Node* list2){
    Node *p1 = list1;
    Node *p2 = list2;

    while (p1 != p2) {
        p1 = (p1 == nullptr) ? list2 : p1->next;
        p2 = (p2 == nullptr) ? list1 : p2->next;
    }

    return p1;
}

int main(){

    List l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);
    
    printLL(l1.head);
    
    List l2;
    l2.push_back(6);
    l2.push_back(7);
    
    printLL(l2.head);
    
    //* create intersection
    createIntersection(l1.head, l2.head);
    cout << "---------------after intersection-------------" << endl;
    printLL(l1.head);
    printLL(l2.head);

    //* getIntersection
    Node *node = getIntersectionNode(l1.head, l2.head);

    cout  << node->val << endl;

    return 0;
}