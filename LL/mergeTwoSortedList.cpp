#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

class Node{
    public:
        int val;
        Node *next;
        Node(int val){
            this->val = val;
            next = NULL;
        };
};

class List{
    public:
    Node *head;
    Node *tail;
        List(){
            head = tail = NULL;
        };

        void push_front(int val){
            Node *newNode = new Node(val);

            if(head == NULL){
                head = tail = newNode;
                return;
            }
            else
            {
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
        void pop_front(){
            if(head == NULL)return;

            Node *temp = head;
            head = head->next;
            temp->next = NULL;

            delete temp;

            if(head == NULL){
                tail = NULL;
            }
        }
        void pop_back(){
            if(head == NULL) return;

            if(head == tail){
                delete head;
                head = NULL;
                tail = NULL;
                return;
            }

            Node *temp = head;
            while(temp->next != tail){
                temp = temp->next;
            };

            temp->next = NULL;
            delete tail;

            tail = temp;
        }
        void printLL(Node *head){
            Node *curr = head;

            while(curr != NULL){
                cout << curr->val << " ";
                curr = curr->next;
            }
            cout << endl;
        }
};

Node* mergeTwoLL(Node *head1, Node *head2){
    Node dummy(-1);
    Node *dtail = &dummy;

    while(head1 && head2){
        if(head1->val <= head2->val){
            dtail->next = head1;
            head1 = head1->next;
        }else{
            dtail->next = head2;
            head2 = head2->next;
        }
        dtail = dtail->next;
    }

    dtail->next = head1 ? head1 : head2;

    return dummy.next;
}


int main(){


    List l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);

    List l2;
    l2.push_back(1);
    l2.push_back(2);
    l2.push_back(3);
    l2.push_back(4);

    l1.printLL(l1.head);
    l1.printLL(l2.head);

    Node * newHead = mergeTwoLL(l1.head,l2.head);
    l1.printLL(newHead);

    return 0;
}