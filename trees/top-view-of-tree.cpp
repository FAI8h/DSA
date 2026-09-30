#include <iostream>
#include <vector>
#include <queue>
#include <map>

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

void topViewOfTree(Node *root, int RHD = 0){// RHD --> Root Horizontal Distance
    queue<pair<Node*, int>> q;

    map<int,int> m;// key = HD, val = root value
    q.push(make_pair(root, 0));// (Node, HD)
    
    while(!q.empty()){
        auto curr = q.front();
        q.pop();

        if(!m.count(curr.second))m[curr.second] = curr.first->val;

        if(curr.first->left != NULL) q.push(make_pair(curr.first->left, curr.second - 1));
        if(curr.first->right != NULL) q.push(make_pair(curr.first->right, curr.second + 1));
    }

    for(auto it : m){
        cout << it.second<< " ";
    }
    cout << endl;
};

void bottomViewOfTree(Node *root, int RHD = 0){// RHD --> Root Horizontal Distance
    queue<pair<Node*, int>> q;

    map<int,int> m;// key = HD, val = root value
    q.push(make_pair(root, 0));// (Node, HD)
    
    while(!q.empty()){
        auto curr = q.front();
        q.pop();

        m[curr.second] = curr.first->val;

        if(curr.first->left != NULL) q.push(make_pair(curr.first->left, curr.second - 1));
        if(curr.first->right != NULL) q.push(make_pair(curr.first->right, curr.second + 1));
    }

    for(auto it : m){
        cout << it.second<< " ";
    }
    cout << endl;
}

int main () {
    vector<int> seq = {1,2,4,-1,-1,5,10,-1,-1,-1,3,6,-1,-1,7,-1,-1};
    Node *root = buildTree(seq);

    topViewOfTree(root);
    bottomViewOfTree(root);
    return 0;
}