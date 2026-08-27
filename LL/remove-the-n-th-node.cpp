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

    return;
}

Node* removeNthNode(Node *head, int n){
    Node *dummy = new Node(-1);
    dummy->next = head;

    Node *slow = dummy;
    Node *fast = dummy;
    for (int i = 0; i < n; i++){
        fast = fast->next;//* makes the fast n steps ahead
    }

    /*
        * after fast n steps ahead move both pointer together when fast-> next reaches null
        * slow pointer will be att exactly before the node we have to remove
    */

    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;// removing the Nth Node

    return dummy->next;
}

int
main(){

    List l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);

    printLL(l.head);
    Node * n = removeNthNode(l.head, 5);
    printLL(n);

    return 0;
}
