#include <iostream>
#include <vector>

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

bool findPath(Node* root, vector<int>& path,int n){
    if(root == NULL) return false;

    path.push_back(root->val);
    if(root->val == n){
        return true;
    }

    bool left = findPath(root->left, path, n);
    bool right = findPath(root->right, path, n);

    if(left || right) return true;

    path.pop_back();
    return false;
};

int LCA(Node *root, int n1, int n2){
    vector<int> path1;
    vector<int> path2;

    findPath(root, path1, n1);
    findPath(root, path2, n2);

    int lca = -1;

    for (int i = 0, j = 0; i < path1.size() && j < path2.size(); i++, j++){
        if(path1[i] != path2[j]){
            return lca;
        }
        lca = path1[i];
    }

    return lca;
}

void printPath(vector<int>& path){
    for(int i : path){
        cout << i << " ";
    }
    cout << endl;
}

int main () {
    vector<int> seq = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1,};
    Node *root = buildTree(seq);

    cout << LCA(root, 4, 5) << endl;
    return 0;
}