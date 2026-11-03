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

void printInRange(Node* root, int st, int end){
    if(root == NULL) return;

    if(st <= root->val && end >= root->val){
        cout << root->val << " ";
        printInRange(root->left, st, end);
        printInRange(root->right, st, end);
    }else if(root->val < st){
        printInRange(root->right, st, end);
    }else{
        printInRange(root->left, st, end);
    }
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

    inOrder(root);
    cout << endl;
    
    printInRange(root, 5, 8);
    cout << endl;
    return 0;
}