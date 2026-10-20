#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace  std;

struct Node{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val): val(val){
        left = right = NULL;
    };
};

static int idx = -1;

Node* buildTree(vector<int>& seq){
    idx++;

    if(seq[idx] == -1) return NULL;

    Node *root = new Node(seq[idx]);

    root->left = buildTree(seq);
    root->right = buildTree(seq);

    return root;
};


void preOrder(Node* root){
    if(root == NULL){
        cout << " -1 ";
        return;
    };

    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
};

void inOrder(Node* root){
    if(root == NULL){
        cout << " -1 ";
        return;
    };

    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
};

void postOrder(Node* root){
    if(root == NULL){
        cout << " -1 ";
        return;
    };

    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
};

void levelOrder(Node* root){
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        
        if(curr == NULL){
            if(!q.empty()){
                cout << "\n";
                q.push(NULL);
                continue;
            }else{
                break;
            }
        }

        cout << curr->val << " ";

        if(curr->left != NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL){
            q.push(curr->right);
        }
    }
}

int main () {
    vector<int> seq = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(seq);
    
    levelOrder(root);
    cout << endl;
    return 0;
}