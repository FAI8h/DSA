#include <iostream>
#include <vector>

using namespace  std;

struct Node{
    int val;
    Node *left;
    Node *right;
    Node(int val) : val(val) { left = right = NULL; };
};

static int idx = -1;
Node* buildTree(vector<int> &seq){
    idx++;

    if(seq[idx] == -1) return NULL;

    Node *root = new Node(seq[idx]);

    root->left = buildTree(seq);
    root->right = buildTree(seq);

    return root;
};

int dist(Node* root, int n){
    if(root == NULL) return -1;
    if(root->val == n) return 0;

    int left = dist(root->left, n);
    if (left == 0) return left + 1;
    else {int right = dist(root->right, n); return right + 1;}
}


Node* LCA(Node* root, int n1, int n2){
    if (root == NULL) return NULL;

    if(root->val == n1 || root->val == n2) return root;

    Node *left = LCA(root->left, n1, n2);
    Node *right = LCA(root->right, n1, n2);

    if(left == NULL) return right;
    if(right == NULL) return left;

    return root;
}

int min_dist(Node* root, int n1, int n2){
    Node *lca = LCA(root, n1, n2);

    return dist(lca, n1) + dist(lca, n2);
}

int main () {
    vector<int> seq = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1,};
    Node *root = buildTree(seq);

    cout << "min-dist : " << min_dist(root, 4, 6) << endl;

    return 0;
}