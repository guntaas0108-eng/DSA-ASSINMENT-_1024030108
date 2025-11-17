
#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};

void push(Node** head_ref, char new_data) {
   
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = nullptr;

    if ((*head_ref) != nullptr) {
        (*head_ref)->prev = new_node;
    }
    (*head_ref) = new_node;
}

bool isPalindrome(Node* head) {

    if (head == nullptr || head->next == nullptr) {
        return true;
    }

    Node* end = head;
    while (end->next != nullptr) {
        end = end->next;
    }

    Node* start = head;
    while (true) {
 
        if (start->data != end->data) {
            return false;
        }

        if (start == end) {
            break;
        }
        
        if (start->next == end) {
            break;
        }
        start = start->next;
        end = end->prev;
    }
    return true;
}

int main() {
    
    Node* head1 = nullptr;
    // We push 'L', 'E', 'V', 'E', 'L' in reverse to build the list
    // L <- E <- V <- E <- L (head)
    push(&head1, 'L');
    push(&head1, 'E');
    push(&head1, 'V');
    push(&head1, 'E');
    push(&head1, 'L');

    cout << "List 1: L <-> E <-> V <-> E <-> L" << endl;
    cout << "Output: " << boolalpha << isPalindrome(head1) << endl;
    cout << "\n----------------------------------------\n" << endl;

    Node* head2 = nullptr;
    // O <- L <- L <- E <- H (head)
    push(&head2, 'O');
    push(&head2, 'L');
    push(&head2, 'L');
    push(&head2, 'E');
    push(&head2, 'H');

    cout << "List 2: H <-> E <-> L <-> L <-> O" << endl;
    cout << "Output: " << boolalpha << isPalindrome(head2) << endl;
    cout << "\n----------------------------------------\n" << endl;

    Node* head3 = nullptr;
    push(&head3, 'R');
    push(&head3, 'A');
    push(&head3, 'C');
    push(&head3, 'E');
    push(&head3, 'C');
    push(&head3, 'A');
    push(&head3, 'R');

    cout << "List 3: R <-> A <-> C <-> E <-> C <-> A <-> R" << endl;
    cout << "Output: " << boolalpha << isPalindrome(head3) << endl;

    return 0;
}