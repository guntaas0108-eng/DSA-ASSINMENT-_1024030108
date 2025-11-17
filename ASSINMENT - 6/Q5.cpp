#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool isCircular(Node* head) {

    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
       
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

int main() {
    
    Node* head1 = new Node();
    Node* node4 = new Node();
    Node* node6 = new Node();
    Node* node7 = new Node();
    Node* node5 = new Node();

    head1->data = 2;
    head1->next = node4;

    node4->data = 4;
    node4->next = node6;

    node6->data = 6;
    node6->next = node7;

    node7->data = 7;
    node7->next = node5;

    node5->data = 5;
    node5->next = head1; 

    cout << "--- Example 1: Circular List ---" << endl;
    cout << "List: 2 -> 4 -> 6 -> 7 -> 5 -> (back to 2)" << endl;

    cout << "Output: " << boolalpha << isCircular(head1) << endl; 

    cout << "\n----------------------------------------\n" << endl;

    // --- Example 2: Non-Circular (Linear) List ---
    // 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    Node* head2 = new Node();
    Node* node2_2 = new Node();
    Node* node2_3 = new Node();

    head2->data = 1;
    head2->next = node2_2;

    node2_2->data = 2;
    node2_2->next = node2_3;

    node2_3->data = 3;
    node2_3->next = nullptr; 

    cout << "--- Example 2: Linear List ---" << endl;
    cout << "List: 1 -> 2 -> 3 -> NULL" << endl;
    cout << "Output: " << boolalpha << isCircular(head2) << endl; // Output: False

    return 0;
}