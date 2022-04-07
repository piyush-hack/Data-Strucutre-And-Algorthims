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

Node *deletefirst(Node *head)
{
    Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

Node *deleteAtIndex(Node *head, int index)
{
    Node *p = head;
    Node *q = head->next;

    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
    return head;
}

Node *deleteAtend(Node *head)
{
    Node *p = head;
    Node *q = head->next;

    int i= 0;

    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);
    return head;
}


Node *deleteValue(Node *head, int value)
{
    Node *p = head;
    Node *q = head->next;

    while(q->data != value && q->next != NULL){
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
    return head;
}

//Insertion
int main()
{

    Node *head;
    Node *second;
    Node *third;
    Node *fourth;
    Node *fifth;
    Node *sixth;

    // allocating memeory for evry node in heap
    head = (Node *)malloc(sizeof(Node));
    second = (Node *)malloc(sizeof(Node));
    third = (Node *)malloc(sizeof(Node));
    fourth = (Node *)malloc(sizeof(Node));
    fifth = (Node *)malloc(sizeof(Node));
    sixth = (Node *)malloc(sizeof(Node));

    //fedding and Connectiong node
    head->data = 7;
    head->next = second;

    second->data = 8;
    second->next = third;

    third->data = 9;
    third->next = fourth;

    fourth->data = 56;
    fourth->next = fifth;

    fifth->data = 34;
    fifth->next = sixth;

    sixth->data = 6;
    sixth->next = NULL;

    linkedListTraversal(head);

    head = deletefirst(head);
    linkedListTraversal(head);

    int index = 2;
    head = deleteAtIndex(head, index);
    linkedListTraversal(head);

    head = deleteAtend(head);
    linkedListTraversal(head);

    
    head = deleteValue(head , 9);
    linkedListTraversal(head);

    system("pause");
    return 0;
}
