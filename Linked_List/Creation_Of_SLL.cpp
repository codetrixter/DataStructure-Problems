#include <iostream>

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

void printList(Node **head)
{
    while((*head)->next != NULL)
    {
        std::cout << (*head)->data << std::endl;
        (*head) = (*head)->next;
    }
}

int main(int argc, char const *argv[])
{
    int options, element;
    Node *head = NULL;
    while(options != 0)
    {
        std::cout << "Please select the following options to perform the respective actions..." << std::endl;
        std::cout << "1: Insert an Element into the linked liist" << std::endl;
        std::cout << "2: Print the linked liist" << std::endl;
        std::cout << "0: Exit" << std::endl;
        std::cin >> options;
        std::cin >> element;

        switch(options)
        {
            case 1:
                std::cout << "input the datta you want to insert at the beginning of the list" << std::endl;
                insertAtBeg(&head, element);
                break;
            case 2:
                printList(&head);
            default :
            break;
        }
    }
    return 0;
}
