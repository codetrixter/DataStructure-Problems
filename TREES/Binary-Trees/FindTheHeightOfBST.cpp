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

    //Parameterized constructor
    BSTNode(int value) : 
    data(value),
    left(NULL),
    right(NULL)
    {}

    BSTNode* createTreeNode(int value);

    BSTNode* insertNode(BSTNode **root, int value);

    //bool searchNode(BSTNode **root, int value);

    int findMin(BSTNode **root);
    int findMax(BSTNode **root);

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


int main(int argc, char const *argv[])
{
    BSTNode rootObj, *rootNode = NULL;
    rootObj.insertNode(&rootNode,50);
    rootObj.insertNode(&rootNode,20);
    rootObj.insertNode(&rootNode,70);
    rootObj.insertNode(&rootNode,10);
    rootObj.insertNode(&rootNode,5);

    std::cout << rootNode->data << std::endl;
    std::cout << rootNode->left->data << std::endl;
    std::cout << rootNode->right->data << std::endl;
    std::cout << rootNode->left->left->data << std::endl;
    std::cout << rootNode->left->left->left->data << std::endl;

    return 0;
}
