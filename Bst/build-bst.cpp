#include <iostream>
#include <vector>

using namespace  std;

struct Node{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val) : val(val) {
        left = right = NULL;
    }
};

Node* insert(Node* root, int val){
    if(root == NULL){
        root = new Node(val);
        return root;
    };

    if(root->val > val){
        root->left = insert(root->left, val);
    }else{
        root->right = insert(root->right, val);
    };
    return root;
}

Node *buildBST(vector<int> &seq){
    int n = seq.size();
    Node *root = NULL;

    for (int i = 0; i < n; i++){
        root = insert(root, seq[i]);
    }
    return root;
}

void inOrder(Node *root){
    if(root == NULL) return;

    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

int main() {
    vector<int> seq = {5, 1, 3, 4, 2, 7};
    // vector<int> seq = {8,5,3,1,4,6,10,11,14};
    Node* root = buildBST(seq);

    inOrder(root);

    cout << endl;
    return 0;
}