#include"TreeNode.h"

TreeNode::TreeNode()
{
    pLeft = pRight = parent = nullptr;
    data = 0;
}

TreeNode::TreeNode(int data, TreeNode* pLeft, TreeNode* pRight, TreeNode* parent)
{
    this->data = data;
    this->pLeft = pLeft;
    this->pRight = pRight;
    this->parent = parent;
}

TreeNode* TreeNode::GetLessNode()
{
    return pLeft;
}

void TreeNode::SetLessNode(TreeNode* newNode)
{
    pLeft = newNode;
}

TreeNode* TreeNode::GetMoreNode()
{
    return pRight;
}

void TreeNode::SetMoreNode(TreeNode* newNode)
{
    pRight = newNode;
}

int TreeNode::GetData()
{
    return data;
}

void TreeNode::SetData(int newData)
{
    data = newData;
}
