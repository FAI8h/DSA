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
}

void preOrder(Node* root){
    if(root == NULL) {
        cout << " -1 ";
        return;
    }
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
};

bool isUniTree(Node* root, int val){
    if(root == NULL) return true;

    if(root->val != val) return false;

    return isUniTree(root->left, val) && isUniTree(root->right, val);
};

int main(){
    vector<int> seq = {2, 2, 2, -1, -1, 2, -1, -1, 2, -1, 2, -1, -1};
    Node *root = buildTree(seq);

    cout << isUniTree(root, 2) << endl;
    return 0;
}