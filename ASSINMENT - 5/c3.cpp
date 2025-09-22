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
void findMiddle();

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

    cout << "List: ";
    display();

    findMiddle();

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

void findMiddle()
{
    if (head == NULL)
    {
        cout << "List empty\n";
        return;
    }
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Middle element: " << slow->data << endl;
}