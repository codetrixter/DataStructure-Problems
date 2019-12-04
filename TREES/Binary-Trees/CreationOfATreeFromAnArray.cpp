#include <iostream>
#include <vector>
#include <queue>

class TreeNode
{
    public:
        void constructARootNode(std::vector<int> &arr);

        void creationOfATree(std::vector<TreeNode*> &vecNode, int i, std::vector<int> &arr);

        void LevelOrderTraversal(std::queue<TreeNode*> &tempQ, int index, std::vector<int> &arr);
        //Contructors
        TreeNode(int D, TreeNode* L, TreeNode* R) : data(D), left(L), right(R)
        {

        }

        TreeNode()
        {
            data = 0;
            left = NULL;
            right = NULL;
        }

    private:
        int data;
        TreeNode* left;
        TreeNode* right; 
};

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
    std::vector<TreeNode*> vecNode;
    if(vecNode.empty())
    {
        TreeNode* node = new TreeNode();
        node->data = arr[0];
        vecNode.push_back(node);
    }

    for(int i = 0; i < arr.size(); i++)
    {
        creationOfATree(vecNode, i, arr);
    }
}

int main(int argc, char const *argv[])
{
    std::vector<int> array = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    TreeNode treeNode;

    treeNode.constructARootNode(array);

    return 0;
}
