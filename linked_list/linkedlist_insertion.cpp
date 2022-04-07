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
void linkedListTraversal(Node *ptr)
{

    std::cout << std::endl;
    std::cout << std::endl;

    while (ptr != NULL)
    {
        std::cout << " " << ptr->data;
        ptr = ptr->next;
    }

    std::cout << std::endl;
}

Node *insertAtFirst(Node *head, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->next = head;
    ptr->data = data;

    return ptr;
}

Node *insertAtIndex(Node *head, int data, int index)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    Node *p = head;

    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

Node *insertAtEnd(Node *head, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;

    Node *p = head;

    while (p->next != NULL)
    {

        p = p->next;
    }

    ptr->next = NULL;
    p->next = ptr;

    return head;
}

Node *insertAfterNode(Node *head, Node *prevNode, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    Node *p = head;

    ptr->next= prevNode->next;
    prevNode->next = ptr;

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
    fourth->next = NULL;

    linkedListTraversal(head);

    head = insertAtFirst(head, 65);

    linkedListTraversal(head);

    insertAtIndex(head, 17, 2);

    linkedListTraversal(head);

    insertAtEnd(head, 99);

    linkedListTraversal(head);

    insertAfterNode(head, second, 45);

    linkedListTraversal(head);


    system("pause");
    return 0;
}
