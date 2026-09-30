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

//pair (diameter, height)
pair<int,int> treeDiameter(Node *root){
    if(root == NULL) return make_pair(0, 0);

    pair<int, int> left = treeDiameter(root->left);
    pair<int, int> right = treeDiameter(root->right);

    int currDiam = left.second + right.second + 1;
    int finalDiam = max(currDiam, max(left.first, right.first));
    int finalHt = max(left.second, right.second) + 1;

    return make_pair(finalDiam, finalHt);
}

int main () {
    vector<int> seq = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node *root = buildTree(seq);
    cout << treeDiameter(root).second << endl;

    return 0;
}