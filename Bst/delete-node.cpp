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

/*
* @params Node to find inOrder Successor
* returns {Node* pointer}
*/
Node* IS(Node* root){
    while(root->left != NULL){
        root = root->left;
    };

    return root;
}

Node *deleteNode(Node *root, int val) {
    if(root == NULL) return NULL;

    if(val < root->val){
        root->left = deleteNode(root->left, val);
    }else if(val > root->val){
        root->right = deleteNode(root->right, val);
    }else{
        //* 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        //* 1 child
        if(root->left == NULL || root->right == NULL){
            return root->left == NULL ? root->right : root->left;
        }

        //* 2 child
        Node *Is = IS(root->right);
        root->val = Is->val;
        root->right = deleteNode(root->right, Is->val);
    }

    return root;
};

void inOrder(Node* root){
    if (root == NULL) return;

    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

int main(){
    vector<int> seq = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node *root = buildBst(seq);


    inOrder(root);
    cout << endl;
    
    inOrder(deleteNode(root, 4));
    cout << endl;
    return 0;
}