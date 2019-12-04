#include <iostream>
#include <vector>
#include <queue>

class TreeNode
{
    public:
        void constructARootNode(std::vector<int> &arr);

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

void TreeNode::LevelOrderTraversal(std::queue<TreeNode*> &tempQ, int index, std::vector<int> &arr)
{
    int sizeQ = tempQ.size();

    if(((index*2)+1) < arr.size())
    {
        int leftIndex = (index*2)+1;
        TreeNode* tempNode = new TreeNode();
        tempNode->data = arr[leftIndex];
        //tempQ.front()->left = tempNode;
        tempQ.push(tempNode);
    }
    if(((index*2)+2) < arr.size())
    {
        int rightIndex = (index*2)+2;
        TreeNode* tempNode = new TreeNode();
        tempNode->data = arr[rightIndex];
        //tempQ.front()->right = tempNode;
        tempQ.push(tempNode);
    }
    while (sizeQ-- != 0)
    {
        std::cout  << tempQ.front()->data << "\t";
        tempQ.pop();
    }
}

void TreeNode::constructARootNode(std::vector<int> &arr)
{
    std::queue<TreeNode*> QNode;
    if(QNode.empty())
    {
        TreeNode* node = new TreeNode();
        node->data = arr[0];
        QNode.push(node);
    }

    for(int i = 0; i < arr.size(); i++)
    {
        LevelOrderTraversal(QNode, i, arr);
    }
}

int main(int argc, char const *argv[])
{
    std::vector<int> array = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    TreeNode treeNode;

    treeNode.constructARootNode(array);

    return 0;
}
