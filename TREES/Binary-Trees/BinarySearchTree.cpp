/**
 * BST creation iteratively.
 */

#include <iostream>
//------------Original Approach-----------

// class BSTNode
// {
//     public:
//     //Default constructor.
//     BSTNode ():
//       data(0)
//     , left(NULL)
//     , right(NULL)
//     {}

//     //Parameterized constructor.
//     BSTNode(int value):
//       data(value)
//     , left(NULL)
//     , right(NULL)
//     {}

//     void insertNode(BSTNode **root, int value)
//     {
//         BSTNode *newNode = new BSTNode(value);
//         BSTNode *head, *temp;
//         head = (*root);

//         if((*root) == NULL)
//         {
//             (*root) = newNode;
//             return;
//         }
        
//         while(head != NULL)
//         {
//             if(value <= head->data)
//             {
//                 temp = head;
//                 head = head->left;
//             }
//             else if(value > head->data)
//             {
//                 temp = head;
//                 head = head->right;
//             }
//         }
//         if((value <= temp->data))
//         {
//             temp->left = newNode;
//         }
//         else if ((value > temp->data))
//         {
//             temp->right = newNode;
//         }
//     }

//     public:
//     int data;
//     BSTNode *left;
//     BSTNode *right;
// };

//-----------Recursive Approach---------------

class BSTNode
{
    public:

    //Default constructor.
    BSTNode ():
      data(0)
    , left(NULL)
    , right(NULL)
    {}

    //Parameterized constructor
    BSTNode(int value) : 
    data(value),
    left(NULL),
    right(NULL)
    {}

    BSTNode* createTreeNode(int value);

    BSTNode* insertNode(BSTNode **root, int value);

    bool searchNode(BSTNode **root, int value);

    public:
    int data;
    BSTNode *left;
    BSTNode *right;
};

BSTNode* BSTNode::createTreeNode(int value)
{
    BSTNode *newNode = new BSTNode(value);        
    return newNode;
}

BSTNode* BSTNode::insertNode(BSTNode **root, int value)
{
    if(*root == NULL)
    {
        *root = createTreeNode(value);
    }
    else if(value  <= (*root)->data)
    {
        (*root)->left = insertNode(&((*root)->left), value);
    }
    else
    {
        (*root)->right = insertNode(&((*root)->right), value);
    }
    return *root;
}

bool BSTNode::searchNode(BSTNode **root, int value)
{
    if(*root == NULL)
    {
        return false;   
    }
    else if((*root)->data == value)
    {
        return true;
    }
    else if(value  <= (*root)->data)
    {
        return searchNode(&((*root)->left), value);
    }
    else
    {
        return searchNode(&((*root)->right), value);
    }
}

int main(int argc, char const *argv[])
{
    BSTNode rootObj, *rootNode = NULL;
    rootObj.insertNode(&rootNode,50);
    rootObj.insertNode(&rootNode,20);
    rootObj.insertNode(&rootNode,70);
    rootObj.insertNode(&rootNode,10);
    rootObj.insertNode(&rootNode,5);

    std::cout << rootObj.searchNode(&rootNode, 100);
    std::cout << rootObj.searchNode(&rootNode, 20);

    std::cout << rootNode->data << std::endl;
    std::cout << rootNode->left->data << std::endl;
    std::cout << rootNode->right->data << std::endl;
    std::cout << rootNode->left->left->data << std::endl;
    std::cout << rootNode->left->left->left->data << std::endl;

    return 0;
}
