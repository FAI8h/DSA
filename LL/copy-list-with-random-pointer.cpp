#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <unordered_map>

using namespace  std;

class Node{
public:
    int val;
    Node *next;
    Node *random;

    Node(int val){
        this->val = val;
        next = NULL;
        random = NULL;
    }
};

class List{
    Node* find(int val){
        Node *curr = head;

        while(curr != NULL){
            if(curr->val == val){
                return curr;
            }
            curr = curr->next;
        }

        return NULL;
    }

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

    void setRandom(int from, int to){
        Node *fromNode = find(from);
        Node *toNode = find(to);

        if(fromNode != NULL){
            fromNode->random = toNode;
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
void printLLRandom(Node *head){
    Node *curr = head;

    while(curr != NULL){
        cout << "( " << curr->val << " -> " << curr->random->val << " ) -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

Node *copyWithRandom(Node *head){
    unordered_map<Node *, Node*> m;
    Node *curr = head;

    while(curr != NULL){
        Node *newNode = new Node(curr->val);

        m[curr] = newNode;
        curr = curr->next;
    }
    
    curr = head;

    while(curr != NULL){
        m[curr]->next = m[curr->next];
        m[curr]->random = m[curr->random];
        curr = curr->next;
    }

    return m[head];
}

int main(){

    List l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);

    l.setRandom(1, 4);
    l.setRandom(3, 4);
    l.setRandom(4, 1);
    l.setRandom(2, 3);
    l.setRandom(5, 3);


    printLL(l.head);

    Node *newHead = copyWithRandom(l.head);

    printLL(newHead);

    return 0;
}