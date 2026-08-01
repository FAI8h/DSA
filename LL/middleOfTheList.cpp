#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

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

        void push_front(int num){
            Node *newNode = new Node(num);

            if(head == NULL){
                head = tail = newNode;
                return;
            }else{
                newNode->next = head;
                head = newNode;
            }
        }

        void push_back(int num){
            Node *newNode = new Node(num);
            
            if(head == NULL){
                head = tail = newNode;
                return;
            }else{
                tail->next = newNode;
                tail = newNode;
            }
        }

        void middleOfLL(){
            Node *slow = head, *fast = head;

            while(fast != NULL && fast->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
            }

            cout << slow->data << endl;
        }

        void reverseLL(){
            Node *curr = head;
            Node *prev = NULL;
            Node *currNext = NULL;

            while(curr != NULL){
                currNext = curr->next;
                curr->next = prev;
                prev = curr;
                curr = currNext;
            }
            head = prev;
        }

        void printll(){
            Node *temp = head;

            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main() {
    List l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.printll();
    l.reverseLL();
    l.printll();

    return 0;
};