#include <iostream>
using namespace std;
struct ll
{
    int data;
    struct ll *next;
};
typedef struct ll node;
node *head = NULL;
node *tail = head;
int count = 0;
void print();
void deletespecifickey();
int main()
{
    int n;
    cin >> n;
    int i = 0;
    while (i != n)
    {

        if (head == NULL)
        {
            head = new node;
            int x;
            cin >> x;
            head->data = x;
            head->next = NULL;
            tail = head;
        }
        else
        {
            tail->next = new node;
            cin >> tail->next->data;
            tail->next->next = NULL;
            tail = tail->next;
        }
        i++;
    }
    print();
    deletespecifickey();
    cout << endl;
    print();
}
void print()
{

    node *p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
        count++;
    }
}
void deletespecifickey()
{
    int x;
    cin >> x;
    int cnt = 0;
    while (head != NULL && head->data == x)
    {
        node *temp = head;
        head = head->next;
        delete temp;
        cnt++;
    }
    node *p = head;
    while (p != NULL && p->next != NULL)
    {
        if (p->next->data == x)
        {
            node *temp = p->next;
            p->next = p->next->next;
            delete temp;
            cnt++;
        }
        else
        {
            p = p->next;
        }
    }
    cout << cnt << endl;
}