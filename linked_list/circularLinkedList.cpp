#include <iostream>
#include <cstdlib>

using namespace std;

class Node
{
private:
    /* data */
public:
    int data;
    Node *next;
};

// linked list traversal
void circularlinkedListTraversal(Node *head)
{
    Node *ptr = head;

    std::cout << std::endl;
    std::cout << std::endl;

    do
    {
        std::cout << " " << ptr->data;
        ptr = ptr->next;
    } while (ptr != head);

    std::cout << std::endl;
}

Node *insertAtFirst(Node *head, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }

    // At this point p points at the last of circular linked list

    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

//Insertion
int main()
{

    Node *head;
    Node *second;
    Node *third;
    Node *fourth;

    // allocating memeory for evry node in heap
    head = (Node *)malloc(sizeof(Node));
    second = (Node *)malloc(sizeof(Node));
    third = (Node *)malloc(sizeof(Node));
    fourth = (Node *)malloc(sizeof(Node));

    //fedding and Connectiong node
    head->data = 7;
    head->next = second;

    second->data = 8;
    second->next = third;

    third->data = 9;
    third->next = fourth;

    fourth->data = 10;
    fourth->next = head;

    circularlinkedListTraversal(head);
    head = insertAtFirst(head, 80);
    circularlinkedListTraversal(head);
    system("pause");
    return 0;
}
