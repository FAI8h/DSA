#include <iostream>
#include <vector>

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

int sumOfNodes(Node *root){
    if(root == NULL) return 0;

    int left = sumOfNodes(root->left);
    int right = sumOfNodes(root->right);

    return left + right + 1;
}

int main () {
    vector<int> seq = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node *root = buildTree(seq);
    cout << sumOfNodes(root) << endl;
    return 0;
}