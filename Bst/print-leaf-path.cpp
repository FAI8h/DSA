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

Node* insert(Node * root, int val){
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
}

Node* buildBst(vector<int> & seq){
    int n = seq.size();
    Node *root = NULL;

    for (int i = 0; i < n; i++){
        root = insert(root, seq[i]);
    }

    return root;
}

void printPath(vector<int> &p){
    for(int n : p){
        cout << n << " ";
    }
    cout << endl;
}

void paths(Node* root, vector<int> & path){
    if(root == NULL) return;

    path.push_back(root->val);
    paths(root->left, path);
    paths(root->right, path);

    if(root->left == NULL && root->right == NULL){
        printPath(path);
    };

    path.pop_back();
}

void inOrder(Node* root){
    if (root == NULL) return;

    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

int main () {
    vector<int> seq = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node *root = buildBst(seq);
    vector<int> p;

    inOrder(root);
    cout << endl;
    cout << endl;
    paths(root, p);
    cout << endl;

    return 0;
}