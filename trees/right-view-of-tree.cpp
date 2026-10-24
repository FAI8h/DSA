#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <queue>


using namespace  std;

struct Node{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val): val(val){
        left = right = NULL;
    }
};

static int idx = -1;

Node* buildTree(vector<int> &seq){
    idx++;

    if(seq[idx] == -1) return NULL;

    Node *root = new Node(seq[idx]);

    root->left = buildTree(seq);
    root->right = buildTree(seq);

    return root;
};


void topView(Node* root){
    queue<pair<Node *, int>> q; // (Node, HD)
    q.push(make_pair(root, 0));

    map<int, int> m;//HD, value -> root->value

    while(!q.empty()){
        pair<Node *, int> curr = q.front();
        q.pop();

        if(!m.count(curr.second)) m[curr.second] = curr.first->val;

        if(curr.first->left != NULL) q.push(make_pair(curr.first->left, curr.second -1));
        if(curr.first->right != NULL) q.push(make_pair(curr.first->right, curr.second +1));
    };

    for(pair<int,int> it : m){
        cout << it.second << " ";
    };
    cout << endl;

}
void bottomView(Node* root){
    queue<pair<Node *, int>> q; // (Node, HD)
    q.push(make_pair(root, 0));

    map<int, int> m;//HD, value -> root->value

    while(!q.empty()){
        pair<Node *, int> curr = q.front();
        q.pop();
        m[curr.second] = curr.first->val;

        if(curr.first->left != NULL) q.push(make_pair(curr.first->left, curr.second -1));
        if(curr.first->right != NULL) q.push(make_pair(curr.first->right, curr.second +1));
    };

    for(pair<int,int> it : m){
        cout << it.second << " ";
    };
    cout << endl;
};

void rightView(Node* root){
    queue<pair<Node *, int>> q;// (Node, VD), vertical distance
    map<int, int> m; // <VD, value>

    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<Node *, int> curr = q.front();
        q.pop();

        if(!m.count(curr.second)) m[curr.second] = curr.first->val;

        if(curr.first->right != NULL) q.push(make_pair(curr.first->right, curr.second + 1));
        if(curr.first->left != NULL) q.push(make_pair(curr.first->left, curr.second + 1));
    };

    for (pair<int, int> it: m){
        cout << it.second << " ";
    };
    cout << endl;
}
void leftView(Node* root){
    queue<pair<Node *, int>> q;// (Node, VD), vertical distance
    map<int, int> m; // <VD, value>

    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<Node *, int> curr = q.front();
        q.pop();

        if(!m.count(curr.second)) m[curr.second] = curr.first->val;

        if(curr.first->left != NULL) q.push(make_pair(curr.first->left, curr.second + 1));
        if(curr.first->right != NULL) q.push(make_pair(curr.first->right, curr.second + 1));
    };

    for (pair<int, int> it: m){
        cout << it.second << " ";
    };
    cout << endl;
}

int main () {
    vector<int> seq = {1, 2, 4, -1, -1, 5, -1, 8,-1,-1, 3, -1, 6, -1, 7, -1,-1};
    Node *root = buildTree(seq);

    topView(root);
    bottomView(root);
    rightView(root);
    leftView(root);
    return 0;
}