#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

struct Node{
    int val;
    Node *left;
    Node *right;

    Node(int val){
        this->val = val;
        left = right = NULL;
    }
};

static int idx = -1;

Node* buildTree(vector<int>& seq){
    idx++;

    if(seq[idx] == -1) return NULL;

    Node *root = new Node(seq[idx]);

    root->left = buildTree(seq);
    root->right = buildTree(seq);

    return root;
};


bool isIdenticalTree(Node* r1, Node* r2){
    if(r1 == NULL && r2 == NULL)
        return true;
    if (r1 == NULL || r2 == NULL)
        return false;

    if(r1->val != r2->val){
        return false;
    }

    return isIdenticalTree(r1->left, r2->left) && isIdenticalTree(r1->right, r2->right);
}

bool isSubTree(Node* root, Node* subRoot){
    if(root == NULL && subRoot == NULL)
        return true;

    if(root == NULL || subRoot == NULL)
        return false;

    if(root->val == subRoot->val){
        if(isIdenticalTree(root, subRoot)) return true;
    }

    bool left = isSubTree(root->left, subRoot);
    if(!left){
        return isSubTree(root->right, subRoot);
    }

    return true;
}

int main () {
    vector<int> seq = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(seq);
    Node *subRoot = new Node(2);
    subRoot->left = new Node(4);
    subRoot->right = new Node(5);

    cout << isSubTree(root, subRoot) << endl;

    return 0;
}