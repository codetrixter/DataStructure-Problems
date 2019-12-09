/**
 * ------------------------CONTAINS CREATION OF TREE FROM AN ARRAYS------------------------
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

class TreeNode
{
    public:
        void constructARootNode(std::vector<int> &arr);

        void creationOfATree(std::vector<TreeNode*> &vecNode, int i, std::vector<int> &arr);

        void LevelOrderTraversal(std::queue<TreeNode*> &tempQ, int index, std::vector<int> &arr);

        TreeNode getRootNode();

        void preOrderTraversal();

        //Contructors
        TreeNode(int D, TreeNode* L, TreeNode* R) : data(D), left(L), right(R)
        {

        }

        TreeNode()
        {
            data = 0;
            left = NULL;
            right = NULL;
            vecNode = {};
        }

    private:
        int                         data;
        TreeNode*                   left;
        TreeNode*                   right; 
        std::vector<TreeNode*>      vecNode;
};

TreeNode TreeNode::getRootNode()
{
    return  *vecNode[0];
}

void TreeNode:: preOrderTraversal()
{
    std::stack<TreeNode*> bufferTree;
    TreeNode currentNode = getRootNode();
    TreeNode *currentNodePtr = &currentNode; 

    while(currentNodePtr != NULL || !(bufferTree.empty()))
    {
        if((currentNodePtr != NULL) && (currentNodePtr->right != NULL))
        {
            bufferTree.push(currentNodePtr->right);
        }

        if(currentNodePtr == NULL && !(bufferTree.empty()))
        {
            currentNodePtr = bufferTree.top();
            bufferTree.pop();
            continue;
        }
        std::cout << currentNodePtr->data << "\t";
        currentNodePtr = currentNodePtr->left;
    }
}

void TreeNode::creationOfATree(std::vector<TreeNode*> &vecNode, int index, std::vector<int> &arr)
{
    if(((index*2)+1) < arr.size())
    {
        int leftIndex = (index*2)+1;
        TreeNode* tempNode = new TreeNode();
        tempNode->data = arr[leftIndex];
        vecNode[index]->left = tempNode;
        vecNode.push_back(tempNode);
    }
    if(((index*2)+2) < arr.size())
    {
        int rightIndex = (index*2)+2;
        TreeNode* tempNode = new TreeNode();
        tempNode->data = arr[rightIndex];
        vecNode[index]->right = tempNode;
        vecNode.push_back(tempNode);
    }
}

void TreeNode::constructARootNode(std::vector<int> &arr)
{ 
    TreeNode* node = new TreeNode();

    if(vecNode.empty())
    {
        TreeNode* tempNode;
        node->data = arr[0];
        tempNode = node;
        vecNode.push_back(tempNode);
    }

    for(int i = 0; i < arr.size(); i++)
    {
        creationOfATree(vecNode, i, arr);
    }
}

int main(int argc, char const *argv[])
{
    std::vector<int> array = {1, 2, 3, 4, 5};
    TreeNode treeNode;

    treeNode.constructARootNode(array);

    std::cout << "Level Order Traversal of he Binary tree :: " << std::endl;
    for(int item: array)
    {
        std::cout << item << "\t";
    }

    std::cout << "\n preOrder traversal of the Binary tree is :: " << std::endl;

    treeNode.preOrderTraversal();

    return 0;
}
