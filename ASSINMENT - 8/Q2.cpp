#include <iostream>
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

Node* searchRecursive(Node* root, int key) {

    if (root == nullptr || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return searchRecursive(root->left, key);
    }

    return searchRecursive(root->right, key);
}

Node* searchIterative(Node* root, int key) {
    Node* current = root;
    while (current != nullptr) {
        if (key == current->data) {
            return current; 
        } else if (key < current->data) {
            current = current->left; 
        } else {
            current = current->right;
        }
    }
    return nullptr; 
}

Node* findMax(Node* root) {

    if (root == nullptr) {
        return nullptr;
    }

    Node* current = root;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current;
}

Node* findMin(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }

    Node* current = root;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

Node* inOrderSuccessor(Node* root, Node* n) {
    if (n == nullptr) return nullptr;
    if (n->right != nullptr) {
        return findMin(n->right);
    }

    Node* successor = nullptr;
    Node* current = root;
    
    while (current != nullptr) {
        if (n->data < current->data) {
            successor = current;
            current = current->left;
        } else if (n->data > current->data) {
            current = current->right;
        } else {
            break;
        }
    }
    return successor;
}

Node* inOrderPredecessor(Node* root, Node* n) {
    if (n == nullptr) return nullptr;

    if (n->left != nullptr) {
        return findMax(n->left);
    }

    Node* predecessor = nullptr;
    Node* current = root;
    
    while (current != nullptr) {
        if (n->data > current->data) {
            predecessor = current;
            current = current->right;
        } else if (n->data < current->data) {
           
            current = current->left;
        } else {
            break;
        }
    }
    return predecessor;
}


int main() {
    Node* root = nullptr;

    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 35);
    
    cout << boolalpha;
    
    cout << "--- (a) Search ---" << endl;
    cout << "Searching for 15 (Recursive): " << (searchRecursive(root, 15) != nullptr) << endl;
    cout << "Searching for 99 (Recursive): " << (searchRecursive(root, 99) != nullptr) << endl;
    cout << "Searching for 25 (Iterative): " << (searchIterative(root, 25) != nullptr) << endl;
    cout << "Searching for 1 (Iterative):  " << (searchIterative(root, 1) != nullptr) << endl;

    cout << "\n--- (b) Maximum Element ---" << endl;
    Node* maxNode = findMax(root);
    if (maxNode != nullptr) {
        cout << "Maximum element is: " << maxNode->data << endl;
    }

    cout << "\n--- (c) Minimum Element ---" << endl;
    Node* minNode = findMin(root);
    if (minNode != nullptr) {
        cout << "Minimum element is: " << minNode->data << endl;
    }

    cout << "\n--- (d) In-order Successor ---" << endl;

    Node* node10 = searchIterative(root, 10);
    Node* succ10 = inOrderSuccessor(root, node10);
    cout << "Successor of 10 is: " << succ10->data << endl;

    Node* node15 = searchIterative(root, 15);
    Node* succ15 = inOrderSuccessor(root, node15);
    cout << "Successor of 15 is: " << succ15->data << endl;
    

    Node* node35 = searchIterative(root, 35);
    Node* succ35 = inOrderSuccessor(root, node35);
    cout << "Successor of 35 is: " << (succ35 == nullptr ? "None" : "Error") << endl;

    cout << "\n--- (e) In-order Predecessor ---" << endl;

    Node* pred10 = inOrderPredecessor(root, node10);
    cout << "Predecessor of 10 is: " << pred10->data << endl;

    Node* node25 = searchIterative(root, 25);
    Node* pred25 = inOrderPredecessor(root, node25);
    cout << "Predecessor of 25 is: " << pred25->data << endl;

    Node* node5 = searchIterative(root, 5);
    Node* pred5 = inOrderPredecessor(root, node5);
    cout << "Predecessor of 5 is: " << (pred5 == nullptr ? "None" : "Error") << endl;

    return 0;
}