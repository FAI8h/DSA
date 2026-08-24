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

        void push_front(int val){
            Node *newNode = new Node(val);
            
            if(head == NULL){
                head = tail = newNode;
                return;
            }else{
                newNode->next = head;
                head = newNode;
                return;
            }
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

Node* reverseInRange(Node *head, int left, int right){
    if(left == right) return head;
    if(head->next == NULL) return head;
    Node *curr = head;
    Node *beforeLeft = NULL;
    Node *afterRight = NULL;
    Node *leftNode = NULL;
    Node *rightNode = NULL;

    for (Node *i = head; i != NULL; i = i->next){
        
    }

        while (curr != NULL)
        {
            if (curr->next != NULL && curr->next->val == left)
                beforeLeft = curr;
            if (curr->val == left)
                leftNode = curr;
            if (curr->val == right)
                rightNode = curr;
            if (rightNode != NULL)
                afterRight = rightNode->next;
            curr = curr->next;
        }

    // * reverse
    Node *curr1 = leftNode;// starting of the range //* head
    Node *prev = NULL;
    Node *next = NULL;

    while(curr1 != afterRight){
        next = curr1->next;
        curr1->next = prev;

        prev = curr1;
        curr1 = next;
    }

    beforeLeft->next = rightNode;
    leftNode->next = afterRight;

    return head;
}

int main () {

    List l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);
    printLL(l1.head);
    
    reverseInRange(l1.head, 2, 5);
    printLL(l1.head);

    return 0;
}
