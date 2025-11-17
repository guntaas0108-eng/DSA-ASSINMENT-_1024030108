#include <iostream>
using namespace std;

// --- 1. Doubly Linked List ---

struct Node_DLL {
    int data;
    Node_DLL* next;
    Node_DLL* prev;
};

int getSize_DLL(Node_DLL* head) {
    int count = 0;
    Node_DLL* current = head; 

    while (current != nullptr) {
        count++;
        current = current->next; 
    }
    
    return count;
}
// --- 2. Circular Linked List ---

struct Node_CLL {
    int data;
    Node_CLL* next;
};


int getSize_CLL(Node_CLL* head) {
    // Handle the empty list case
    if (head == nullptr) {
        return 0;
    }

    int count = 0;
    Node_CLL* temp = head;


    do {
        count++;
        temp = temp->next;
    } while (temp != head); 

    return count;
}


int main() {
    
    cout << "--- Doubly Linked List Size Demo ---" << endl;

    Node_DLL* head_dll = new Node_DLL();
    Node_DLL* second_dll = new Node_DLL();
    Node_DLL* third_dll = new Node_DLL();

    head_dll->data = 10;
    head_dll->prev = nullptr; 
    head_dll->next = second_dll;

    second_dll->data = 20;
    second_dll->prev = head_dll;
    second_dll->next = third_dll;

    third_dll->data = 30;
    third_dll->prev = second_dll;
    third_dll->next = nullptr; 


    cout << "List: 10 <-> 20 <-> 30" << endl;
    cout << "Calculated Size: " << getSize_DLL(head_dll) << endl; 

    Node_DLL* empty_dll = nullptr;
    cout << "\nList: (Empty)" << endl;
    cout << "Calculated Size: " << getSize_DLL(empty_dll) << endl; 
    cout << "\n----------------------------------------\n" << endl;
    cout << "--- Circular Linked List Size Demo ---" << endl;

    Node_CLL* head_cll = new Node_CLL();
    Node_CLL* second_cll = new Node_CLL();
    Node_CLL* third_cll = new Node_CLL();

    head_cll->data = 1;
    head_cll->next = second_cll;

    second_cll->data = 2;
    second_cll->next = third_cll;

    third_cll->data = 3;
    third_cll->next = head_cll; 


    cout << "List: 1 -> 2 -> 3 -> (back to 1)" << endl;
    cout << "Calculated Size: " << getSize_CLL(head_cll) << endl; 


    Node_CLL* empty_cll = nullptr;
    cout << "\nList: (Empty)" << endl;
    cout << "Calculated Size: " << getSize_CLL(empty_cll) << endl; 

    return 0;
}