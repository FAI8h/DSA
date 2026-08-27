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

    Node *dummy = new Node(-1);
    Node *curr = NULL;// points at the left / starting point of the sublist & this will be sublist new Tail
    Node *prev = NULL;// points at the left - 1 / before starting of the sublist

    dummy->next = head;
    prev = dummy;
    for (int i = 0; i < left - 1; i++){
        prev = prev->next;
    }

    curr = prev->next; // setting the curr pointer to the start of the sublist

    //* reverse the node
    Node *temp = curr;// pointing to head
    Node *tempNext = NULL;
    Node *tempPrev = NULL; // this will become new sublist head

    for (int i = 0; i <= right - left; i++){
        tempNext = temp->next;
        temp->next = tempPrev;

        tempPrev = temp;
        temp = tempNext;
    }

    prev->next = tempPrev;
    curr->next = temp;

    //* this is so important if the sublist starts at very head then after reverse will change the given head so do not return head; instead return dummy->next;
    return dummy->next;
}

int main () {

    List l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);
    printLL(l1.head);
    
    reverseInRange(l1.head, 2, 4);
    printLL(l1.head);

    return 0;
}
