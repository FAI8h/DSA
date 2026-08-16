#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

class Node{
    public:
        int data;
        Node *next;
        Node(int val){
            data = val;
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
            }else{
                newNode->next = head;
                head = newNode;
            };
        };

        void push_back(int val){
            Node *newNode = new Node(val);

            if(head == NULL){
                head = tail = newNode;
            }else{
                tail->next = newNode;
                tail = newNode;
            };
        };

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

        void printLL(){
            Node *curr = head;
            while (curr != NULL)
            {
                cout << curr->data << " -> ";
                curr = curr->next;
            }
            cout<<"NULL" << endl;
        }
};

int middleOfLL(Node *head){
    Node *slow = head;
    Node *fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    };

    return slow->data;
}

int main () {
    List l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);

    l.printLL();

    cout << middleOfLL(l.head) << endl;

    return 0;
}