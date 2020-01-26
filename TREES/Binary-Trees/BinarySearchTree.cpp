/**
 * BST creation iteratively.
 */

#include <iostream>

class BSTNode
{
    public:
    //Default constructor.
    BSTNode ():
      data(0)
    , left(NULL)
    , right(NULL)
    {}

    //Parameterized constructor.
    BSTNode(int value):
      data(value)
    , left(NULL)
    , right(NULL)
    {}

    void insertNode(BSTNode **root, int value)
    {
        BSTNode *newNode = new BSTNode(value);
        BSTNode *head, *temp;
        head = (*root);

        if((*root) == NULL)
        {
            (*root) = newNode;
            return;
        }
        
        while(head != NULL)
        {
            if(value <= head->data)
            {
                temp = head;
                head = head->left;
            }
            else if(value > head->data)
            {
                temp = head;
                head = head->right;
            }
        }
        if((value <= temp->data))
        {
            temp->left = newNode;
        }
        else if ((value > temp->data))
        {
            temp->right = newNode;
        }
    }

    public:
    int data;
    BSTNode *left;
    BSTNode *right;
};

int main(int argc, char const *argv[])
{
    BSTNode rootObj, *rootNode = NULL;
    rootObj.insertNode(&rootNode,50);
    rootObj.insertNode(&rootNode,20);
    rootObj.insertNode(&rootNode,10);
    rootObj.insertNode(&rootNode,70);

    std::cout << rootNode->data << std::endl;
    std::cout << rootNode->left->data << std::endl;
    std::cout << rootNode->right->data << std::endl;
    std::cout << rootNode->left->left->data << std::endl;

    return 0;
}
