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

void inOrder(Node *root){
    if(root == NULL)return;

    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

void rangeSum(Node* root, int low, int high, int &sum){
    if(root == NULL) return;

    if(low <= root->val && high >= root->val){
        rangeSum(root->left, low, high, sum);
        sum += root->val;
        rangeSum(root->right, low, high, sum);
    }else if(low > root->val){
        rangeSum(root->right, low, high, sum);
    }else{
        rangeSum(root->left, low, high, sum);
    }
}



int main () {
    vector<int> seq = {6,2,8,0,4,7,9,3,5};
    Node *root = buildBst(seq);

    inOrder(root);
    cout << endl;

    int sum = 0;
    rangeSum(root, 6, 9, sum);
    cout << sum << endl;

    return 0;
}