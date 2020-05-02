#include"BinaryTree.h"
#include"TreeNode.h"

BinaryTree::BinaryTree()
{
    root = nullptr;
}

BinaryTree::BinaryTree(TreeNode* firstNode)
{
    root = firstNode;
}

BinaryTree::~BinaryTree()
{
    Destoy(root);
}

void BinaryTree::Destoy(TreeNode* node)
{
    if (node)
    {
        Destoy(node->pLeft);
        Destoy(node->pRight);
        delete node;
    }
}

void BinaryTree::Insert(TreeNode* n, const int& val)
{
    TreeNode* ptr = root;
    TreeNode* ptr1 = nullptr;

    while (ptr != 0)
    {
        ptr1 = ptr;
        if (val < ptr->data)
            ptr = ptr->pLeft;
        else
            ptr = ptr->pRight;
    }

    n->parent = ptr1;
    if (ptr1 == 0)
        root = n;
    else
    {
        if (val < ptr1->data)
            ptr1->pLeft = n;
        else
            ptr1->pRight = n;
    }
}

TreeNode* BinaryTree::Search(TreeNode* n, const int& val)
{

    if (n == 0 || val == n->GetData())
    {
        return n;
    }

    if (val > n->GetData())
        return Search(n->pRight, val);
    else
        return Search(n->pLeft, val);
}


void BinaryTree::Insert(const int& x)
{
    TreeNode* n = new TreeNode(x);
    Insert(n, x);
}

TreeNode* BinaryTree::Search(const int& val)
{
    return Search(root, val);
}