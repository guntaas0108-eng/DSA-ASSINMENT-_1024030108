#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Error: Memory allocation failed!" << endl;
        return nullptr;
    }
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// --- 1. Pre-order Traversal ---

void preorderTraversal(Node* root) {

    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";

    preorderTraversal(root->left);
    preorderTraversal(root->right);
}


// --- 2. In-order Traversal ---

void inorderTraversal(Node* root) {

    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);

    cout << root->data << " ";

    inorderTraversal(root->right);
}

// --- 3. Post-order Traversal ---

void postorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);

    cout << root->data << " ";
}

int main() {

    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);

    cout << "Binary Tree Traversals (Recursive):" << endl;
    cout << "------------------------------------" << endl;


    cout << "Pre-order (Root, Left, Right): " << endl;
    cout << "  ";
    preorderTraversal(root);
  
    cout << endl;

  
    cout << "\nIn-order (Left, Root, Right): " << endl;
    cout << "  ";
    inorderTraversal(root);
  
    cout << endl;


    cout << "\nPost-order (Left, Right, Root): " << endl;
    cout << "  ";
    postorderTraversal(root);

    cout << endl;

    return 0;
}