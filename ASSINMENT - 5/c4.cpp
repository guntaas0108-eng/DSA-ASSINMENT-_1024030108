#include <iostream>
using namespace std;

struct ll
{
    int data;
    struct ll *next;
};
typedef struct ll node;

node *head = NULL;
node *tail = NULL;

void display();
void reverse();

int main()
{
    int n, x;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        node *t = new node;
        t->data = x;
        t->next = NULL;

        if (head == NULL)
        {
            head = t;
            tail = t;
        }
        else
        {
            tail->next = t;
            tail = t;
        }
    }

    cout << "Original List: ";
    display();

    reverse();

    cout << "Reversed List: ";
    display();

    return 0;
}

void display()
{
    node *p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void reverse()
{
    node *prev = NULL;
    node *curr = head;
    node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}