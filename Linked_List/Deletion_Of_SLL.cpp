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
    Node *temp;
    if((*head_node) == NULL)
    {
        std::cout << "underflow" << std::endl;
    }

    temp = (*head_node);
    (*head_node) = (*head_node)->next;
    std::free(temp);
}

void deleteAtEnd(Node **head_node)
{
    Node *iter = (*head_node);
    Node *prev = (*head_node);
    Node *temp;
    if((*head_node) == NULL)
    {
        std::cout << "underflow" << std::endl;
    }

    while(iter->next != NULL)
    {
        prev = iter;
        iter = iter->next;
    }

    prev->next = NULL;
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

void printList(Node *head_node)
{
    while(head_node != NULL)
    {
        std::cout << head_node->data << "\t";
        head_node = head_node->next;
    }
}

void insertAtEnd(Node **node_head, int element)
{
    Node *newNode = new Node();

    newNode->data = element;
    //adding null to the next of new node.
    newNode->next = NULL;

    Node *last = (*node_head);

    //if node is NULL
    if((*node_head) == NULL)
    {
        (*node_head) = newNode;
        return;
    }

    //traversing the linked list
    while(last->next != NULL)
    {
        last = last->next;
    }

    //insertion at end
    last->next = newNode;
}

int main(int argc, char const *argv[])
{
    int options, element = 0, position = 0;
    Node *head = NULL;
    do
    {
        std::cout << "Please select the following options to perform the respective actions..." << std::endl;
        std::cout << "1: Delete an Element into the linked list at the begining" << std::endl;
        std::cout << "2: Delete an Element into the linked list at the end" << std::endl;
        std::cout << "3: Delete an Element into the linked list at the given location" << std::endl;
        std::cout << "4: Print the linked liist" << std::endl;
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
