#include <iostream>
#include <vector>

using namespace std;

struct Node{
public:
    int val;
    Node* left;
    Node *right;

    Node(int val) : val(val){
        left = right = NULL;
    }
};

Node* insert(Node* root, int val){
    if(root == NULL){
        root = new Node(val);
        return root;
    }

    if(val < root->val){
        root->left = insert(root->left, val);
    }else{
        root->right = insert(root->right, val);
    }

    return root;
};

Node* buildBST(vector<int> &seq){
    Node *root = NULL;

    for(int val : seq){
        root = insert(root, val);
    };

    return root;
};

void inOrder(Node* root){
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

int LCA(Node* root, int n1, int n2){
    if(root == NULL) return -1;
    if(root->val == n1 || root->val == n2){
        return root->val;
    }

    if((n1 < root->val) && (n2 < root->val)){
        return LCA(root->left, n1, n2);
    }else if((n1 > root->val) && (n2 > root->val)){
        return LCA(root->right, n1, n2);
    }else{
        return root->val;
    }
}

int main(){
    vector<int> seq = {6,2,8,0,4,7,9,3,5};
    Node *root = buildBST(seq);

    inOrder(root);
    cout << endl;
    cout << LCA(root, 2, 8);
    cout << endl;

    return 0;
}