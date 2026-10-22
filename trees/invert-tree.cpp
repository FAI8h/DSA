#include <iostream>
#include <vector>

using namespace  std;

struct Node{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val): val(val){
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

Node* invert(Node* root){
    if(root == NULL) return root;

    Node *left = invert(root->left);
    Node *right = invert(root->right);

    root->right = left;
    root->left = right;

    return root;
};

void preOrder(Node* root){
    if(root == NULL) {
        cout << " -1 ";
        return;
    }
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
};

int main () {
    vector<int> seq = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1,};
    Node *root = buildTree(seq);

    preOrder(invert(root));
    cout << endl;
    return 0;
}