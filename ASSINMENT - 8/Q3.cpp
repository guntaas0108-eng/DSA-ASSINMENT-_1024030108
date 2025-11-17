#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int data) {

    if (root == nullptr) {
        return new Node(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

Node* findMin(Node* node) {
    Node* current = node;

    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int data) {

    if (root == nullptr) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } 

    else {

        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp; 
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp; 
        }

        Node* temp = findMin(root->right);

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int maxDepth(Node* root) {

    if (root == nullptr) {
        return 0;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return 1 + max(leftDepth, rightDepth);
}

int minDepth(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);

    if (leftDepth == 0 || rightDepth == 0) {
        return 1 + max(leftDepth, rightDepth);
    } else {
        return 1 + min(leftDepth, rightDepth);
    }
}

void inorderPrint(Node* root) {
    if (root == nullptr) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main() {
    Node* root = nullptr;

    cout << "--- Testing Insertion ---" << endl;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    
    cout << "Original tree (in-order): ";
    inorderPrint(root);
    cout << endl;

    cout << "Inserting duplicate 40..." << endl;
    insert(root, 40);
    cout << "Tree after duplicate insert: ";
    inorderPrint(root);
    cout << endl;

    cout << "\n--- Testing Depths ---" << endl;
    cout << "Max Depth (Height): " << maxDepth(root) << endl; 
    cout << "Min Depth: " << minDepth(root) << endl; 


    cout << "\nAdding 90 and 100 to make tree unbalanced..." << endl;
    insert(root, 90);
    insert(root, 100);

    cout << "Max Depth (unbalanced): " << maxDepth(root) << endl; 
    cout << "Min Depth (unbalanced): " << minDepth(root) << endl; 
    cout << "\n--- Testing Deletion ---" << endl;
    cout << "Deleting leaf node 20..." << endl;
    root = deleteNode(root, 20);
    cout << "Tree: ";
    inorderPrint(root);
    cout << endl;

    cout << "Deleting node 80 (has one child)..." << endl;
    root = deleteNode(root, 80);
    cout << "Tree: ";
    inorderPrint(root);
    cout << endl;

    cout << "Deleting root node 50 (has two children)..." << endl;
    root = deleteNode(root, 50);
    cout << "Tree: ";
    inorderPrint(root); 
    cout << endl;

    return 0;
}