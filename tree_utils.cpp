#include "tree_utils.h"

// Build the tree by user input
node* BuildTree(node *root) {
    cout << "Enter the data" << endl;
    int data;
    cin >> data;
    if (data == -1) return NULL;
    
    root = new node(data);
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = BuildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = BuildTree(root->right);
    return root;
}

// Level-order traversal of the tree
void levelOrder(node *root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node *temp = q.front();
        q.pop();
        if (temp == NULL) {
            // cout << endl;
            if (!q.empty()) q.push(NULL);
        } else {
            cout << temp->data << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
}

// In-order traversal
void inorder(node *root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Pre-order traversal
void preorder(node *root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Post-order traversal
void postorder(node *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Build tree from level-order input
void Build_from_LOT(node *&root) {
    queue<node*> q;
    cout << "Enter The Data for the root: ";
    int data;
    cin >> data;

    root = new node(data);
    q.push(root);

    while (!q.empty()) {
        node *temp = q.front();
        q.pop();
        cout << "Enter left node for: " << temp->data << endl;
        int leftdata;
        cin >> leftdata;
        if (leftdata != -1) {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightdata;
        cin >> rightdata;
        if (rightdata != -1) {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

// Count the number of leaf nodes
int countLeaf(node *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeaf(root->left) + countLeaf(root->right);
}

// Check if the tree is balanced
pair<bool, int> balanceCheck(node *root) {
    if (root == NULL) return make_pair(true, 0);
    
    pair<bool, int> left = balanceCheck(root->left);
    pair<bool, int> right = balanceCheck(root->right);
    
    bool balanced = abs(left.second - right.second) <= 1;
    int height = max(left.second, right.second) + 1;
    
    return make_pair(left.first && right.first && balanced, height);
}

// Check if the tree is balanced (helper function)
void isBalance(node *root) {
    pair<bool, int> result = balanceCheck(root);
    if (result.first) {
        cout << "The tree is balanced" << endl;
    } else {
        cout << "The tree is not balanced" << endl;
    }
}

// Check if two trees are identical
bool isIndentical(node *r1, node *r2) {
    if (r1 == NULL && r2 == NULL) return true;
    if (r1 == NULL || r2 == NULL) return false;

    return (r1->data == r2->data) && isIndentical(r1->left, r2->left) && isIndentical(r1->right, r2->right);
}

// Check if the tree is a sum tree
pair<bool, int> sum(node *root) {
    if (root == NULL) return make_pair(true, 0);
    if (root->left == NULL && root->right == NULL) return make_pair(true, root->data);

    pair<bool, int> left = sum(root->left);
    pair<bool, int> right = sum(root->right);

    bool isSum = (root->data == left.second + right.second);
    return make_pair(left.first && right.first && isSum, root->data + left.second + right.second);
}

// Check if the tree is a sum tree (helper function)
bool isSumTree(node *root) {
    return sum(root).first;
}
int getHeight(node * root){
    if(root==NULL){
        return 0;
    }
    int left= getHeight(root->left);
    int right=getHeight(root->right);

    int ans=max(left,right)+1;

    return ans;
}
