#include <iostream>
#include <vector>

using namespace  std;

struct Node{
public:
    int val;
    Node* left;
    Node *right;

    Node(int val) : val(val){
        left = right = NULL;
    };
};

static int idx = -1;
Node* buildTree(vector<int> & seq){
    idx++;

    if(seq[idx] == -1) return NULL;

    Node * root = new Node(seq[idx]);

    root->left = buildTree(seq);
    root->right = buildTree(seq);

    return root;
};


Node* removeLeaf(Node* root, int val){
    if(root == NULL) return NULL;

    Node* left = removeLeaf(root->left, val);
    Node* right = removeLeaf(root->right, val);

    if(left == NULL && right == NULL && root->val == val){
        return NULL;
    };

    root->left = left;
    root->right = right;

    return root;
}

void preOrder(Node* root){
    if(root == NULL) return;

    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main () {
    vector<int> seq = {1,2,2,-1,-1,2,-1,-1,3,-1,6,-1,-1};
    Node *root = buildTree(seq);
    preOrder(root);

    cout << endl;
    Node *newRoot = removeLeaf(root, 2);
    
    preOrder(newRoot);
    cout << endl;
    return 0;
}