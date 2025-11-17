#include <iostream>
#include <climits> 
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool isBSTUtil(Node* node, long minVal, long maxVal) {

    if (node == nullptr) {
        return true;
    }

    if (node->data <= minVal || node->data >= maxVal) {
        return false;
    }

    return

        isBSTUtil(node->left, minVal, node->data) &&
        isBSTUtil(node->right, node->data, maxVal);
}

bool isBST(Node* root) {

    return isBSTUtil(root, LONG_MIN, LONG_MAX);
}

int main() {
    Node* root1 = new Node(20);
    root1->left = new Node(10);
    root1->right = new Node(30);
    root1->left->left = new Node(5);
    root1->left->right = new Node(15);
    
    cout << "--- Example 1 (Valid BST) ---" << endl;
    cout << "Is this a BST? " << isBST(root1) << endl; // Expected: true
    cout << "\n--------------------------------\n" << endl;

    Node* root2 = new Node(20);
    root2->left = new Node(10);
    root2->right = new Node(30);
    root2->right->left = new Node(18); 

    cout << "--- Example 2 (Invalid BST) ---" << endl;
    cout << "Is this a BST? " << isBST(root2) << endl; 

    return 0;
}