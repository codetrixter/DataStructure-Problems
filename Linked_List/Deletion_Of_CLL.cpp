#include <iostream>
#include <cstdlib>

class Node
{
    public:
    int data;
    Node *next;
};

void deleteAtBeg(Node **head_node)
{
    Node *temp = new Node();
    Node *iterate = (*head_node);
    Node *first = (*head_node);

    if((*head_node) == NULL)
    {
        std::cout << "underflow" << std::endl;
    }

    //updating the last node's next pointer.
    while(iterate->next != first)
    {
        iterate = iterate->next;
    }

    temp = (*head_node);
    iterate->next = first->next;
    (*head_node) = first->next;

    std::free(temp);
}

void deleteAtEnd(Node **head_node)
{
    Node *iter = (*head_node);
    Node *prev = (*head_node);
    Node *first = (*head_node);
    // /Node *temp = new node();
    if((*head_node) == NULL)
    {
        std::cout << "underflow" << std::endl;
    }

    while(iter->next != first)
    {
        prev = iter;
        iter = iter->next;
    }

    prev->next = first;
    std::free(iter);
}

void deleteAtPos(Node **head_node, int pos)
{
    Node *iterate = (*head_node);
    Node *prev = (*head_node);
    Node *temp;

    while(((pos-1) != 0) && (iterate->next != NULL))
    {
        prev = iterate;
        iterate = iterate->next;
        pos--;
    }

    temp = iterate;
    prev->next = iterate->next;
    std::free(temp);    
}

void printList(Node *head)
{
    Node *temp = head;

    do
    {
        std::cout << temp->data << "\t";
        temp = temp->next;
    }while(temp != head);
}

void insertAtEnd(Node **node_head, int element)
{
    Node *newNode = new Node();
    Node *first = (*node_head);

    newNode->data = element;
    //adding null to the next of new node.
    newNode->next = first;

    Node *iterate = (*node_head);

    //if node is NULL
    if((*node_head) == NULL)
    {
        newNode->next = newNode;
        (*node_head) = newNode;
        return;
    }

    //traversing the linked list
    while(iterate->next != first)
    {
        iterate = iterate->next;
    }

    //insertion at end
    iterate->next = newNode;
}

int main(int argc, char const *argv[])
{
    int options, element = 0, position = 0;
    Node *head = NULL;
    do
    {
        std::cout << "Please select the following options to perform the respective actions on Circular Linked List..." << std::endl;
        std::cout << "1: Delete an Element into the linked list at the begining" << std::endl;
        std::cout << "2: Delete an Element into the linked list at the end" << std::endl;
        std::cout << "3: Delete an Element into the linked list at the given location" << std::endl;
        std::cout << "4: Print the linked list" << std::endl;
        std::cout << "5: Insert the element into the LL at the end" << std::endl;
        std::cout << "0: Exit" << std::endl;
        std::cin >> options;

        switch(options)
        {
            case 1:
                deleteAtBeg(&head);
                std::cout << "Deleted successfully" << std::endl;
                break;
            case 2:
                deleteAtEnd(&head);
                std::cout << "Deleted successfully" << std::endl;
                break;
            case 3:
                std::cin >> position ;
                deleteAtPos(&head, position);
                std::cout << "Deleted successfully" << std::endl;
                break;
            case 4:
                printList(head);
                std::cout << std::endl;
                break;
            case 5:
                std::cin >> element;
                insertAtEnd(&head, element);
                break;
            case 0:
                std::cout << "O enetered.... exiting..." << std::endl;
                std::exit(0);
            default :
                std::cout << "Invalid entry" << std::endl;
        }
    }while(options != 0);
    return 0;
}
