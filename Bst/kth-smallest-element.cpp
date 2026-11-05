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

Node *insert(Node *root, int val){
    if(root == NULL){
        root = new Node(val);
        return root;
    };

    if(val < root->val){
        root->left = insert(root->left, val);
    }else{
        root->right = insert(root->right, val);
    }

    return root;
};

Node* buildBST(vector<int>& seq){
    Node *root = NULL;

    for(int val : seq){
        root = insert(root, val);
    };

    return root;
}

void inOrder(Node* root){
    if(root == NULL) return;

    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

void kthSmallest(Node *root, int k, vector<int>& ans){
    if(root == NULL) return;

    kthSmallest(root->left, k,ans);
    ans.push_back(root->val);
    kthSmallest(root->right, k, ans);
}



void kthSmallest(Node *root, int k, int &count, int& result){
    if(root == NULL || count >= k) return;

    kthSmallest(root->left, k, count, result);
    count++;
    if(count == k){
        result = root->val;
        return;
    }
    kthSmallest(root->right, k, count, result);
}

int main(){
    vector<int> seq = {8, 4, 3, 1, 5, 9, 10, 11, 14};
    Node *root = buildBST(seq);

    inOrder(root);
    cout << endl;
    int k = 3;
    int count = 0;
    int result = -1;
    kthSmallest(root, k, count, result);
    cout << result;
    cout << endl;
    return 0;
}