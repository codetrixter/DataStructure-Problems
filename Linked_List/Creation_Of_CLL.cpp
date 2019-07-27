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
    Node *iterate = (*head_ref);
    Node *first = (*head_ref);

    //insert data into the new node.
    newNode->data = element;

    if((*head_ref) == NULL)
    {
        newNode->next = newNode;
        (*head_ref) = newNode;
        return;
    }

    //changing the last pointer's next as beg has been updated.
    while(iterate->next != first)
    {
        iterate = iterate->next;
    }
    iterate->next = newNode;
    
    //updating the first node
    newNode->next = (*head_ref);

    //make newNode as a start.
    (*head_ref) = newNode;

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

void insertAtPos(Node **head_node, int pos)
{
    Node *newNode = new Node();
    Node *first = (*head_node);
    Node *prev = (*head_node);

    newNode->data = 1000;

    Node *iterate = (*head_node);
    Node *iterate2 = (*head_node);

    if(pos == 1)
    {
        //changing the last pointer's next as beg has been updated.
        while(iterate2->next != first)
        {
            iterate2 = iterate2->next;
        }
        iterate2->next = newNode;
        
        //updating the first node
        newNode->next = (*head_node);

        //make newNode as a start.
        (*head_node) = newNode;

        return;
    }

    while(((pos-1) != 0) && (iterate->next != first))
    {
        prev = iterate;
        iterate = iterate->next;
        pos--;
    }

    prev->next = newNode;
    newNode->next = iterate;   
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

int main(int argc, char const *argv[])
{
    int options, element = 0, position = 0;
    Node *head = NULL;
    do
    {
        std::cout << "Please select the following options to perform the respective actions on Circular Linked List..." << std::endl;
        std::cout << "1: Insert an Element into the linked list at the begining" << std::endl;
        std::cout << "2: Insert an Element into the linked list at the end" << std::endl;
        std::cout << "3: Insert an Element into the linked list at the given location" << std::endl;
        std::cout << "4: Print the linked list" << std::endl;
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
