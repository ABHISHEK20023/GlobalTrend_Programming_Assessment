/*
Write a function to reverse a singly linked list.
The function should take the head of the list and return the new head of the reversed list.
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        next = nullptr;
    }
    Node()
    {
        val = 0;
        next = nullptr;
    }
};
Node *createListNode()
{
    int val;
    cout << "please enter node values and in the end press -1" << endl;
    cout << "Example : 1 2 7 4 2 -1" << endl;
    cin >> val;
    Node *head = nullptr;
    Node *tail = nullptr;
    while (val != -1)
    {
        if (!head)
        {
            head = new Node(val);
            tail = head;
        }
        else
        {
            tail->next = new Node(val);
            tail = tail->next;
        }
        cin >> val;
    }

    return head;
}

Node *reverseList(Node *head)
{
    if (head == nullptr or head->next == nullptr)
    {
        return head;
    }
    Node *prev = nullptr;
    Node *curr = head;
    while (curr)
    {
        Node *nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

void printList(Node *head)
{
    Node *curr = head;
    while (curr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    return;
}

int main()
{
    Node *head = createListNode();
    cout << "List before : ";
    printList(head);
    head = reverseList(head);
    cout << endl;
    cout << "List after reversing : ";
    printList(head);
}