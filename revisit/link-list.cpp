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
    Node *head;
    Node *tail;

    public:
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
            if(head == NULL){
                return;
            }

            Node *temp = head;
            head = head->next;
            temp->next = NULL;
            
            delete temp;
        };
        void pop_back(){
            if(head == NULL){
                return;
            }

            Node *temp = head;
            while(temp->next != tail || temp->next->next != NULL){
                temp = temp->next;
            };
            temp->next = NULL;
            delete tail;
            tail = temp;
        };

        void reversell(){
            Node *curr = head;
            Node *prev = NULL;
            Node *next = NULL;

            while (curr != NULL){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            };

            head = prev;
        }

        void printll(){
            Node *curr = head;

            while(curr != NULL){
                cout << curr->data << " ";
                curr = curr->next;
            };
            cout << endl;
        };
};

int main () {

    List l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_front(5);
    
    l.printll();
    
    l.reversell();
    l.printll();
    return 0;
}