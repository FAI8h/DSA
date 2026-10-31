#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node{
public:
    int val;
    Node* left;
    Node *right;

    Node(int val) : val(val){
        left = right = NULL;
    };
};

static int idx = -1;
Node* buildTree(vector<int> & seq){
    idx++;

    if(seq[idx] == -1) return NULL;

    Node * root = new Node(seq[idx]);

    root->left = buildTree(seq);
    root->right = buildTree(seq);

    return root;
};

string duplicate(Node* root, unordered_map<string, int> &m, vector<Node*> & v){
    if( root == NULL) return "";

    string a = duplicate(root->left, m, v);
    string b = duplicate(root->right, m, v);

    string temp = to_string(root->val) + "," + a + "," + b;

    m[temp]++;

    if(m[temp] == 2 && (root->left || root->right)) v.push_back(root); //? This cond : (root->left || root->right) prevents the leaf nodes to be added as a subTree 

    return temp;
}

vector<Node *> findDuplicateSubTree(Node* root){
    unordered_map<string, int> m;
    vector<Node *> v;
    duplicate(root, m, v);

    return v;
}

void preOrder(Node* root){
    if(root == NULL) return;

    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    vector<int> seq = {1,2,4,-1,-1,-1,3,2,4,-1,-1,-1,4,-1,-1};
    Node *root = buildTree(seq);

    preOrder(root);
    cout << endl;

    vector<Node *> nodes = findDuplicateSubTree(root);

    for(auto it : nodes){
        preOrder(it);
    }
    cout << endl;

    return 0;
}