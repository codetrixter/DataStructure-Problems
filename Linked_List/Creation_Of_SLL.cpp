#include <iostream>
#include <cstdlib>

class Node
{
    public:
    int         data;
    Node        *next;
};

void insertAtBeg(Node **head_ref, int element)
{
    //allocate a new node.
    Node *newNode = new Node();

    //insert data into the new node.
    newNode->data = element;

    //make next of newNode point to start.
    newNode->next = (*head_ref);

    //make newNode as a start.
    (*head_ref) = newNode;
}

void insertAtEnd(Node **node_head, int element)
{
    Node *newNode = new Node();

    newNode->data = element;
    //adding null to the next of new node.
    newNode->next = NULL;

    //if node is NULL
    if((*node_head) == NULL)
    {
        (*node_head) = newNode;
        return;
    }

    //traversing the linked list
    while((*node_head)->next != NULL)
    {
        (*node_head) = (*node_head)->next;
    }

    //insertion at end
    (*node_head)->next = newNode;
}

void printList(Node *head)
{
    while(head != NULL)
    {
        std::cout << head->data << std::endl;
        head = head->next;
    }
}

int main(int argc, char const *argv[])
{
    int options= 0, element = 0;
    Node *head = NULL;
    while(options != 0)
    {
        std::cout << "Please select the following options to perform the respective actions..." << std::endl;
        std::cout << "1: Insert an Element into the linked list at the begining" << std::endl;
        std::cout << "2: Insert an Element into the linked list at the end" << std::endl;
        std::cout << "3: Insert an Element into the linked list at the given location" << std::endl;
        std::cout << "4: Print the linked liist" << std::endl;
        std::cout << "0: Exit" << std::endl;
        std::cin >> options;

        switch(options)
        {
            case 1:
                std::cout << "input the data you want to insert at the beginning of the list" << std::endl;
                std::cin >> element;
                insertAtBeg(&head, element);
                break;
            case 2:
                std::cin >> element;
                insertAtEnd(&head, element);
                break;
            case 3:
            case 4:
                printList(head);
                break;
            case 0:
                std::cout << "O enetered.... exiting..." << std::endl;
                std::exit(0);
            default :
                std::cout << "Invalid entry" << std::endl;
        }
    }
    return 0;
}
