#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <unordered_map>

using namespace  std;

class Node {
public:
    Node *next;
    Node *prev;
    int key, val;

    Node(int key, int val){
        this->key = key;
        this->val = val;
        next = prev = NULL;
    }
};

class Dll{
public:
    Node *head;
    Node *tail;

    Dll(){
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void insertAtHead(Node *newNode){
        Node *oldNode = head->next;

        head->next = newNode;
        newNode->prev = head;
        newNode->next = oldNode;

        oldNode->prev = newNode;
    }

    void removeNode(Node *node){
        Node *prev = node->prev;
        Node *next = node->next;

        prev->next = next;
        next->prev = prev;
    }
};

class LRU {
    Dll dl;
    
public:
    unordered_map<int, Node *> m;
    int limit;
    LRU(int cap){
        this->limit = cap;
    }

    int get(int key){
        if(m.find(key) == m.end()){
            return -1;
        }

        Node *MRU = m[key];
        dl.removeNode(MRU);
        dl.insertAtHead(MRU);

        return MRU->val;
    }

    void put(int key, int val){
        if(m.find(key) != m.end()){
            Node *MRU = m[key];
            dl.removeNode(MRU);
            MRU->val = val;
            dl.insertAtHead(MRU);
            return;
        }

        if(m.size() == limit){
            Node *LRU = dl.tail->prev;
            m.erase(LRU->key);
            dl.removeNode(LRU);

            delete LRU;
        }

        Node *newNode = new Node(key, val);
        dl.insertAtHead(newNode);
        m[key] = newNode;
        return;
    }
};

void printDLL(Node *head){
    Node *curr = head;

    while(curr != NULL){
        cout << curr->key << " <=> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

int main () {
    LRU cache(3);

    cache.put(1, 5);
    cache.put(2, 6);
    cache.put(2, 7);
    cache.put(3, 7);
    cache.put(4, 8);

    cout << cache.get(4) << endl;

    return 0;
}