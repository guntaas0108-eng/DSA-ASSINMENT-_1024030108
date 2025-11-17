#include <iostream>
using namespace std;

// 1. DOUBLY LINKED LIST

class DLLNode {
public:
    int data;
    DLLNode* next;
    DLLNode* prev;
};

// Class for Doubly Linked List Operations
class DoublyLinkedList {
public:
    DLLNode* head;

    DoublyLinkedList() {
        head = NULL;
    }

    // (a) Insert as first node
    void insertFirst(int val) {
        DLLNode* newNode = new DLLNode();
        newNode->data = val;
        newNode->prev = NULL;
        newNode->next = head;

        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        cout << "-> Inserted " << val << " at the beginning." << endl;
    }

    // (a) Insert as last node
    void insertLast(int val) {
        DLLNode* newNode = new DLLNode();
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
            cout << "-> Inserted " << val << " as the first node." << endl;
            return;
        }

        DLLNode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
        cout << "-> Inserted " << val << " at the end." << endl;
    }

    // (a) Insert after a specific node
    void insertAfter(int key, int val) {
        DLLNode* temp = head;
        while (temp != NULL && temp->data != key) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "-> Error: Node with key " << key << " not found." << endl;
            return;
        }

        // If 'temp' is the last node
        if (temp->next == NULL) {
            insertLast(val);
            return;
        }

        DLLNode* newNode = new DLLNode();
        newNode->data = val;

        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        cout << "-> Inserted " << val << " after " << key << "." << endl;
    }

    // (a) Insert before a specific node
    void insertBefore(int key, int val) {
        DLLNode* temp = head;
        while (temp != NULL && temp->data != key) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "-> Error: Node with key " << key << " not found." << endl;
            return;
        }

        // If 'temp' is the head node
        if (temp == head) {
            insertFirst(val);
            return;
        }

        DLLNode* newNode = new DLLNode();
        newNode->data = val;

        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
        cout << "-> Inserted " << val << " before " << key << "." << endl;
    }

    // (b) Deletion of a specific node
    void deleteNode(int key) {
        DLLNode* temp = head;
        // Find the node to be deleted
        while (temp != NULL && temp->data != key) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "-> Error: Node with key " << key << " not found." << endl;
            return;
        }

        // Case 1: Node to be deleted is the head
        if (temp == head) {
            head = temp->next;
        }

        // Case 2: Node is not the last node
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }

        // Case 3: Node is not the first node
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }

        delete temp;
        cout << "-> Deleted node with value " << key << "." << endl;
    }

    // (c) Search for a node
    void searchNode(int key) {
        DLLNode* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == key) {
                cout << "-> Found " << key << " at position " << pos << "." << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "-> Node with value " << key << " not found in the list." << endl;
    }

    void displayList() {
        DLLNode* temp = head;
        if (temp == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        cout << "List (forward): NULL <-> ";
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};


// === 2. CIRCULAR (SINGLY) LINKED LIST
// Node structure for a Circular Linked List
class CLLNode {
public:
    int data;
    CLLNode* next;
};

class CircularLinkedList {
public:
    CLLNode* last;

    CircularLinkedList() {
        last = NULL;
    }

    // (a) Insert as first node
    void insertFirst(int val) {
        CLLNode* newNode = new CLLNode();
        newNode->data = val;

        if (last == NULL) {
            last = newNode;
            newNode->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
        }
        cout << "-> Inserted " << val << " at the beginning." << endl;
    }

    // (a) Insert as last node
    void insertLast(int val) {
        CLLNode* newNode = new CLLNode();
        newNode->data = val;

        if (last == NULL) {
            last = newNode;
            newNode->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode; // Update the last pointer
        }
        cout << "-> Inserted " << val << " at the end." << endl;
    }

    // (a) Insert after a specific node
    void insertAfter(int key, int val) {
        if (last == NULL) {
            cout << "-> Error: List is empty." << endl;
            return;
        }

        CLLNode* temp = last->next;
        do {
            if (temp->data == key) {
                CLLNode* newNode = new CLLNode();
                newNode->data = val;
                newNode->next = temp->next;
                temp->next = newNode;
                
                // If the key node was the last node, update last
                if (temp == last) {
                    last = newNode;
                }
                cout << "-> Inserted " << val << " after " << key << "." << endl;
                return;
            }
            temp = temp->next;
        } while (temp != last->next);

        cout << "-> Error: Node with key " << key << " not found." << endl;
    }

    // (a) Insert before a specific node
    void insertBefore(int key, int val) {
        if (last == NULL) {
            cout << "-> Error: List is empty." << endl;
            return;
        }

        CLLNode* temp = last->next;
        CLLNode* prev = last;
        do {
            if (temp->data == key) {
                CLLNode* newNode = new CLLNode();
                newNode->data = val;
                newNode->next = temp;
                prev->next = newNode;
                
                // Note: If inserting before the head (temp == last->next),
                // 'prev' is 'last', so 'last->next' is correctly updated.
                
                cout << "-> Inserted " << val << " before " << key << "." << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != last->next);

        cout << "-> Error: Node with key " << key << " not found." << endl;
    }

    // (b) Deletion of a specific node
    void deleteNode(int key) {
        if (last == NULL) {
            cout << "-> Error: List is empty." << endl;
            return;
        }

        CLLNode* temp = last->next;
        CLLNode* prev = last;

        do {
            if (temp->data == key) {
                // Case 1: Only one node in the list
                if (temp == last && temp->next == last) {
                    last = NULL;
                }
                // Case 2: Deleting the head node
                else if (temp == last->next) {
                    prev->next = temp->next; // last->next = temp->next
                }
                // Case 3: Deleting the last node
                else if (temp == last) {
                    prev->next = temp->next;
                    last = prev; // Update last
                }
                // Case 4: Deleting a middle node
                else {
                    prev->next = temp->next;
                }

                delete temp;
                cout << "-> Deleted node with value " << key << "." << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != last->next);

        cout << "-> Error: Node with key " << key << " not found." << endl;
    }

    // (c) Search for a node
    void searchNode(int key) {
        if (last == NULL) {
            cout << "-> List is empty." << endl;
            return;
        }

        CLLNode* temp = last->next;
        int pos = 1;
        do {
            if (temp->data == key) {
                cout << "-> Found " << key << " at position " << pos << "." << endl;
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != last->next);

        cout << "-> Node with value " << key << " not found in the list." << endl;
    }

    void displayList() {
        if (last == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        CLLNode* temp = last->next;
        cout << "List (circular): ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != last->next);
        cout << "(Back to " << last->next->data << ")" << endl;
    }
};

// === 3. MENU AND MAIN FUNCTION
void showDLLMenu() {
    cout << "\n--- Doubly Linked List Menu ---" << endl;
    cout << "1. Insert at First" << endl;
    cout << "2. Insert at Last" << endl;
    cout << "3. Insert After a Node" << endl;
    cout << "4. Insert Before a Node" << endl;
    cout << "5. Delete a Specific Node" << endl;
    cout << "6. Search for a Node" << endl;
    cout << "7. Display List" << endl;
    cout << "8. Back to Main Menu" << endl;
    cout << "Enter your choice: ";
}

void showCLLMenu() {
    cout << "\n--- Circular Linked List Menu ---" << endl;
    cout << "1. Insert at First" << endl;
    cout << "2. Insert at Last" << endl;
    cout << "3. Insert After a Node" << endl;
    cout << "4. Insert Before a Node" << endl;
    cout << "5. Delete a Specific Node" << endl;
    cout << "6. Search for a Node" << endl;
    cout << "7. Display List" << endl;
    cout << "8. Back to Main Menu" << endl;
    cout << "Enter your choice: ";
}

int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int mainChoice, subChoice;
    int val, key;

    while (true) {
        cout << "\n=========================" << endl;
        cout << "      MAIN MENU" << endl;
        cout << "=========================" << endl;
        cout << "1. Work with Doubly Linked List" << endl;
        cout << "2. Work with Circular Linked List" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice) {
            case 1: // Doubly Linked List
                while (true) {
                    showDLLMenu();
                    cin >> subChoice;
                    if (subChoice == 8) break;

                    switch (subChoice) {
                        case 1:
                            cout << "Enter value to insert: "; cin >> val;
                            dll.insertFirst(val);
                            break;
                        case 2:
                            cout << "Enter value to insert: "; cin >> val;
                            dll.insertLast(val);
                            break;
                        case 3:
                            cout << "Enter key (node data to insert after): "; cin >> key;
                            cout << "Enter new value: "; cin >> val;
                            dll.insertAfter(key, val);
                            break;
                        case 4:
                            cout << "Enter key (node data to insert before): "; cin >> key;
                            cout << "Enter new value: "; cin >> val;
                            dll.insertBefore(key, val);
                            break;
                        case 5:
                            cout << "Enter value to delete (e.g., 60): "; cin >> key;
                            dll.deleteNode(key);
                            break;
                        case 6:
                            cout << "Enter value to search for: "; cin >> key;
                            dll.searchNode(key);
                            break;
                        case 7:
                            dll.displayList();
                            break;
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                    }
                }
                break;

            case 2: // Circular Linked List
                while (true) {
                    showCLLMenu();
                    cin >> subChoice;
                    if (subChoice == 8) break;

                    switch (subChoice) {
                        case 1:
                            cout << "Enter value to insert: "; cin >> val;
                            cll.insertFirst(val);
                            break;
                        case 2:
                            cout << "Enter value to insert: "; cin >> val;
                            cll.insertLast(val);
                            break;
                        case 3:
                            cout << "Enter key (node data to insert after): "; cin >> key;
                            cout << "Enter new value: "; cin >> val;
                            cll.insertAfter(key, val);
                            break;
                        case 4:
                            cout << "Enter key (node data to insert before): "; cin >> key;
                            cout << "Enter new value: "; cin >> val;
                            cll.insertBefore(key, val);
                            break;
                        case 5:
                            cout << "Enter value to delete (e.g., 60): "; cin >> key;
                            cll.deleteNode(key);
                            break;
                        case 6:
                            cout << "Enter value to search for: "; cin >> key;
                            cll.searchNode(key);
                            break;
                        case 7:
                            cll.displayList();
                            break;
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                    }
                }
                break;

            case 3: // Exit
                cout << "Exiting program. Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid main menu choice. Please try again." << endl;
        }
    }

    return 0;
}