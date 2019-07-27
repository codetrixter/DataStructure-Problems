#include <iostream>
#include <cstdlib>

class Node
{
    public:
    int         data;
    Node        *next;
    Node 		*previous;
};

void insertAtBeg(Node **head_ref, int element)
{
    //allocate a new node.
    Node *newNode = new Node();

    //insert data into the new node.
    newNode->data = element;

    //make next of newNode point to previous value.
    newNode->next = (*head_ref);
    newNode->previous = (*head_ref);

    //make newNode as a start.
    (*head_ref) = newNode;
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
    newNode->previous = last;
    last->next = newNode;

}

void insertAtPos(Node **head_node, int pos)
{
    int count = 0, posFound = 0;
    Node *newNode = new Node();
    Node *iterate = (*head_node);

    //insertinf value into newNode so that we can print the list.
    newNode->data = 1000;
    
    //If list is empty.
    if((*head_node) == NULL)
    {
        (*head_node) = newNode;
        (*head_node)->next = NULL;
        (*head_node)->previous = NULL;
    }

    while(((pos-1) != 0) && (iterate->next != NULL))
    {
    	iterate = iterate->next;
    	pos--;
    }

    //now the pointer is pointing to the node at the given position.
    newNode->next = iterate;
    newNode->previous = iterate->previous;
    iterate->previous->next = newNode;
    iterate->previous = newNode;
    
}

void printList(Node *head)
{
    while(head != NULL)
    {
        std::cout << head->data << "\t";
        head = head->next;
    }
}

int main(int argc, char const *argv[])
{
    int options, element = 0, position = 0;
    Node *head = NULL;
    do
    {
        std::cout << "Please select the following options to perform the respective actions on Doubly Linked List..." << std::endl;
        std::cout << "1: Insert an Element into the linked list at the begining" << std::endl;
        std::cout << "2: Insert an Element into the linked list at the end" << std::endl;
        std::cout << "3: Insert an Element into the linked list at the given location" << std::endl;
        std::cout << "4: Print the linked liist" << std::endl;
        std::cout << "0: Exit" << std::endl;
        std::cin >> options;

        switch(options)
        {
            case 1:
                std::cin >> element;
                insertAtBeg(&head, element);
                break;
            case 2:
                std::cin >> element;
                insertAtEnd(&head, element);
                break;
            case 3:
                std::cin >> position;
                insertAtPos(&head, position);
                std::cout << "Inserted successfully" << std::endl;
                break;
            case 4:
                printList(head);
                std::cout << std::endl;
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
