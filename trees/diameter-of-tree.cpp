#include <iostream>
#include <vector>
#include <algorithm>

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

int heightOfTree(Node *root){
    if(root == NULL) return 0;

    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);

    return max(left, right) + 1;
}


int diameterOfTree(Node *root) {
    if(root == NULL) return 0;

    //diameter through root
    int rootDiameter = heightOfTree(root->left) + heightOfTree(root->right) + 1;
    int leftDiameter = diameterOfTree(root->left);
    int rightDiameter = diameterOfTree(root->right);


    return max(rootDiameter, max(leftDiameter, rightDiameter));
};


int main () {
    vector<int> seq = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node *root = buildTree(seq);
    cout << diameterOfTree(root) << endl;

    return 0;
}