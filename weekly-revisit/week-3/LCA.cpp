#include <iostream>
#include <vector>

using namespace std;

struct Node{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val): val(val){
        left = right = NULL;
    };
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

Node* LCA(Node* root, int n1, int n2){
    if(root == NULL) return NULL;

    if(root->val == n1 || root->val == n2) return root;

    Node *left = LCA(root->left, n1, n2);
    Node *right = LCA(root->right, n1, n2);

    if(left == NULL && right == NULL) return NULL;

    if(left == NULL){
        return right;
    }

    if(right == NULL){
        return left;
    };

    return root;
};



int main(){
    vector<int> seq = {1, 2, 4, -1, -1, 5,10,-1,-1,11,-1,-1 , 3, -1, 6, -1, -1};
    Node *root = buildTree(seq);

    cout << LCA(root, 10, 6)->val << endl;
    return 0;
}