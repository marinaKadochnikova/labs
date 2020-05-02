#ifndef TREENODE_H
#define TREENODE_H

class TreeNode
{
    TreeNode* pLeft, * pRight, * parent;
    int data;

    TreeNode();
    TreeNode(int data = 0, TreeNode* pLeft = nullptr, TreeNode* pRight = nullptr, TreeNode* parent = nullptr);
    TreeNode* GetLessNode();
    void SetLessNode(TreeNode* newNode);
    TreeNode* GetMoreNode();
    void SetMoreNode(TreeNode* newNode);
    int GetData();
    void SetData(int newData);

    friend class BinaryTree;
};
#endif