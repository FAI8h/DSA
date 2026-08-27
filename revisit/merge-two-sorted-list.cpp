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

Node *mergeTwoList(Node *list1, Node* list2){
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

int main(){
    List l1;
    List l2;

    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);

    l2.push_back(1);
    l2.push_back(2);
    l2.push_back(3);
    l2.push_back(4);
    l2.push_back(5);

    printLL(l1.head);
    printLL(l2.head);
    Node* d = mergeTwoList(l1.head, l2.head);

    printLL(d);

    return 0;
}