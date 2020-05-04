#ifndef TREENODE_H
#define TREENODE_H

class TreeNode
{
private:
    friend class BinaryTree;
    TreeNode* pLeft, * pRight, * parent;
    int data;
public:
    TreeNode();
    TreeNode(int data = 0, TreeNode* pLeft = nullptr, TreeNode* pRight = nullptr, TreeNode* parent = nullptr);
    TreeNode* GetLessNode();
    void SetLessNode(TreeNode* newNode);
    TreeNode* GetMoreNode();
    void SetMoreNode(TreeNode* newNode);
    int GetData();
    void SetData(int newData);
};
#endif