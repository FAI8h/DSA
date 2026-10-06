#include <iostream>
#include <vector>

using namespace  std;

struct Node{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val) : val(val) { left = right = NULL; };
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

int kthAnsestor(Node* root, int n, int k){
    if(root == NULL) return -1;

    if(root->val == n) return 0;

    int left = kthAnsestor(root->left, n, k);
    int right = kthAnsestor(root->right, n, k);

    if(left == -1 && right == -1) return -1;

    int valid = left == -1 ? right : left;

    if(valid + 1 == k){
        cout << "Kth Ansestor : "<< root->val << endl;
    }

    return valid + 1;
};

int main () {
    vector<int> seq = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1,};
    Node *root = buildTree(seq);
    kthAnsestor(root, 5, 2);
    return 0;
}