#include"TreeNode.h"

TreeNode::TreeNode()
{
    pLeft = pRight = 0;
    data = 0;
}

TreeNode::TreeNode(int data, TreeNode* pLeft, TreeNode* pRight, TreeNode* parent)
{
    this->data = data;
    this->pLeft = pLeft;
    this->pRight = pRight;
    this->parent = parent;
}

void TreeNode::Set(const int& a)
{
    data = a;
    pLeft = pRight = nullptr;
}