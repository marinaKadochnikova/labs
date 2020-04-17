#ifndef TREENODE_H
#define TREENODE_H

class TreeNode
{
    TreeNode* pLeft, * pRight, * parent;
    int data;

    TreeNode();
    TreeNode(int data = 0, TreeNode* pLeft = nullptr, TreeNode* pRight = nullptr, TreeNode* parent = nullptr);
    int GetData() { return data; }
    void Set(const int& a);

    friend class BinaryTree;
};
#endif