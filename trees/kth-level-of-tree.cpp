#include <iostream>
#include <vector>
#include <queue>

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
}

void preOrder(Node *root){
    if(root == NULL){
        cout << " -1 ";
        return;
    }

    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void kthLevel(Node* root, int CL, int k){
    if(root == NULL) return;

    if(CL == k){
        cout << root->val << " ";
    }

    kthLevel(root->left, CL + 1, k);
    kthLevel(root->right, CL + 1, k);
}

void kthLevel(Node* root, int k){
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 1));

    while(!q.empty()){
        auto curr = q.front();
        q.pop();

        if(curr.second == k){
            cout << curr.first->val << " ";
        }

        if(curr.first->left != NULL){
            q.push(make_pair(curr.first->left, curr.second + 1));
        }
        if(curr.first->right != NULL){
            q.push(make_pair(curr.first->right, curr.second + 1));
        }
    }
}

int main () {
    vector<int> seq = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1,};
    Node *root = buildTree(seq);

    kthLevel(root, 1, 3);
    cout << endl;
    kthLevel(root, 3);
    cout << endl;
    return 0;
}