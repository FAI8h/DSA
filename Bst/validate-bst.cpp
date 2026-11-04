#include <climits>
#include <iostream>
#include <vector>

using namespace  std;

struct Node{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val) : val(val){
        left = right = NULL;
    };
};

Node* insert(Node* root, int val){
    if(root==NULL){
        root = new Node(val);
        return root;
    }

    if (val < root->val){
        root->left = insert(root->left, val);
    }else{
        root->right = insert(root->right, val);
    };

    return root;
}

Node* buildTree(vector<int> &seq){
    Node *root = NULL;

    for(int val : seq){
        root = insert(root, val);
    };
    return root;
}

void inOrder(Node* root){
    if(root == NULL) return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

bool validateHelper(Node *root, long min, long max) {
    if(root == NULL) return true;

    if(root->val <= min || root->val >= max) return false;
    
    bool left = validateHelper(root->left, min, root->val);
    bool right = validateHelper(root->right, root->val, max);

    return left && right;
};

bool validateBST(Node* root){
    if(root == NULL) return true;

    return validateHelper(root, LONG_MIN, LONG_MAX);
}

int main(){
    vector<int> seq = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node *root = buildTree(seq);
    // root->left->right->val = 9;

    inOrder(root);
    cout << endl;

    cout << validateBST(root) << endl;

    return 0;
}