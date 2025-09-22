#include <iostream>
using namespace std;

struct ll
{
    int data;
    struct ll *next;
};
typedef struct ll node;

node *head = NULL;

void print();
void insertathead();
void insertattail();
void insertAfterValue();
void insertBeforeValue();
void deletefromhead();
void deletefromtail();
void deletefromspecificplace();
void searchNode();

int main()
{
    int choice;
    while (true)
    {
        cin >> choice;

        switch (choice)
        {
        case 1:
            insertathead();
            break;
        case 2:
            insertattail();
            break;
        case 3:
            insertAfterValue();
            break;
        case 4:
            insertBeforeValue();
            break;
        case 5:
            deletefromhead();
            break;
        case 6:
            deletefromtail();
            break;
        case 7:
            deletefromspecificplace();
            break;
        case 8:
            searchNode();
            break;
        case 9:
            print();
            break;
        case 10:
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
}
void print()
{
    node *p = head;
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }
    cout << "List: ";
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
void insertathead()
{
    node *p = new node;
    cout << "Enter value: ";
    cin >> p->data;
    p->next = head;
    head = p;
}
void insertattail()
{
    node *p = new node;
    cout << "Enter value: ";
    cin >> p->data;
    p->next = NULL;
    if (head == NULL)
    {
        head = p;
        return;
    }
    node *k = head;
    while (k->next != NULL)
        k = k->next;
    k->next = p;
}
void insertAfterValue()
{
    int x;
    cout << "Enter value to insert after: ";
    cin >> x;
    node *k = head;
    while (k != NULL && k->data != x)
    {
        k = k->next;
    }
    if (k == NULL)
    {
        cout << "Value not found\n";
        return;
    }
    node *p = new node;
    cout << "Enter new value: ";
    cin >> p->data;
    p->next = k->next;
    k->next = p;
}
void insertBeforeValue()
{
    int x;
    cout << "Enter value to insert before: ";
    cin >> x;
    if (head == NULL)
        return;
    if (head->data == x)
    {
        insertathead();
        return;
    }
    node *p = head, *q = NULL;
    while (p != NULL && p->data != x)
    {
        q = p;
        p = p->next;
    }
    if (p == NULL)
    {
        cout << "Value not found\n";
        return;
    }
    node *newNode = new node;
    cout << "Enter new value: ";
    cin >> newNode->data;
    newNode->next = p;
    q->next = newNode;
}
void deletefromhead()
{
    if (head == NULL)
        return;
    node *temp = head;
    head = head->next;
    delete temp;
}
void deletefromtail()
{
    if (head == NULL)
        return;
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    node *p = head;
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    delete p->next;
    p->next = NULL;
}
void deletefromspecificplace()
{
    if (head == NULL)
        return;
    int x;
    cout << "Enter value to delete: ";
    cin >> x;

    if (head->data == x)
    {
        node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    node *p = head->next, *q = head;
    while (p != NULL && p->data != x)
    {
        q = p;
        p = p->next;
    }
    if (p == NULL)
    {
        cout << "Value not found\n";
        return;
    }
    q->next = p->next;
    delete p;
}
void searchNode()
{
    int x, pos = 1;
    cout << "Enter value to search: ";
    cin >> x;
    node *p = head;
    while (p != NULL)
    {
        if (p->data == x)
        {
            cout << "Found at position " << pos << endl;
            return;
        }
        p = p->next;
        pos++;
    }
    cout << "Value not found\n";
}