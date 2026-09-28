#include <iostream>
#include <vector>
#include <queue>

using namespace  std;

struct Node{
    int val;
    Node *left;
    Node *right;

    Node(int val){
        this->val = val;
        left = right = NULL;
    }
};

static int idx = -1;

Node* buildTree(vector<int>& seq){
    idx++;

    if(seq[idx] == -1) return NULL;

    Node *root = new Node(seq[idx]);

    root->left = buildTree(seq);
    root->right = buildTree(seq);

    return root;
}

void inOrder(Node * root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

void postOrder(Node *root){
    if(root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

void levelOrder(Node *root){
    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node *currNode = q.front();
        q.pop();

        if(currNode == NULL){
            if(!q.empty()){

                cout << endl;
                q.push(NULL);
                continue;
            }else{
                break;
            }
        }

        cout << currNode->val <<" ";

        if(currNode->left != NULL){
            q.push(currNode->left);
        }

        if(currNode->right != NULL){
            q.push(currNode->right);
        }
    }
}

int main () {
    vector<int> seq = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(seq);
    inOrder(root);

    cout << "\n";
    postOrder(root);
    cout << "\n";
    levelOrder(root);
    return 0;
}