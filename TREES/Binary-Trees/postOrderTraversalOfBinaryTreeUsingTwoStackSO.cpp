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

        void postOrderTraversal();

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

void TreeNode:: postOrderTraversal()
{
    std::stack<TreeNode*> bufferRightTree, bufferLeftTree;
    TreeNode currentNode = getRootNode();
    TreeNode *currentNodePtr = &currentNode; 

    bufferLeftTree.push(currentNodePtr);

    while(!bufferLeftTree.empty())
    {
        bufferRightTree.push(bufferLeftTree.top());
        bufferLeftTree.pop();

        if(bufferRightTree.top()->left != NULL)
        {
            bufferLeftTree.push(bufferRightTree.top()->left);
        }
        
        if(bufferRightTree.top()->right != NULL)
        {
            bufferLeftTree.push(bufferRightTree.top()->right);
        }
    }

    while(!bufferRightTree.empty())
    {
       std::cout << bufferRightTree.top()->data << "\t";
       bufferRightTree.pop();
    }
    std::cout << std::endl; 
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
    std::vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    TreeNode treeNode;

    treeNode.constructARootNode(array);

    std::cout << "Level Order Traversal of he Binary tree :l: " << std::endl;
    for(int item: array)
    {
        std::cout << item << "\t";
    }

    std::cout << "\n postOrder traversal of the Binary tree is :: " << std::endl;

    treeNode.postOrderTraversal();

    return 0;
}
