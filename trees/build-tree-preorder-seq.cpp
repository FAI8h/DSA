#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace  std;


class Node{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val){
        this->val = val;
        left = right = NULL;
    }
};

static int idx = -1;
Node *buildTree(vector<int> &seq){
    idx++;

    if(seq[idx] == -1) return NULL;

    Node *currNode = new Node(seq[idx]);

    currNode->left = buildTree(seq);
    currNode->right = buildTree(seq);

    return currNode;
}

void preOrder(Node *root){
    if(root == NULL){
        cout << "-1" << " ";
        return;
    }
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    vector<int> seq = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node *root = buildTree(seq);
    preOrder(root);

    return 0;
}