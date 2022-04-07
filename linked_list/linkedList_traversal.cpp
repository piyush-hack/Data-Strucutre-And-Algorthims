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
    system("pause");
    return 0;
}
