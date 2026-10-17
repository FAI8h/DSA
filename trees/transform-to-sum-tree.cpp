#include <iostream>
#include <vector>
#include <queue>

using namespace  std;

struct Node{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val): val(val) {
        left = right = NULL;
    };
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

int sumTree(Node *root) {
    if(root == NULL) return 0;

    int leftOld = sumTree(root->left);
    int rightOld = sumTree(root->right);
    int currOld = root->val;

    root->val = leftOld + rightOld;
    if(root->left != NULL){
        root->val += root->left->val;
    }
    if(root->right != NULL){
        root->val += root->right->val;
    }
    return currOld;
};

void preOrder(Node *root){
    if(root == NULL){
        cout << " -1 ";
        return;
    }

    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
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


int main(){
    vector<int> seq = {1,2,4,-1,-1,5,10,-1,-1,-1,3,6,-1,-1,7,-1,-1};
    Node *root = buildTree(seq);
    cout << endl;
    levelOrder(root);
    cout << "\n";
    sumTree(root);
    levelOrder(root);
}