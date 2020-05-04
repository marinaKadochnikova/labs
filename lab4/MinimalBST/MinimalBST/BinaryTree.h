#ifndef BINARYTREE_H
#define BINARYTREE_H

#include"TreeNode.h"

class BinaryTree
{
private:
    TreeNode* root;
    void Insert(TreeNode* n, const int& val);
    TreeNode* Search(TreeNode* n, const int& val);

public:
    BinaryTree();
    BinaryTree(TreeNode* firstNode);
    ~BinaryTree();
    void Destoy(TreeNode* node);
    void Insert(const int& x);
    TreeNode* Search(const int& val);
    TreeNode* CreateMinimalBST(int* arr, int s, int e);
};
#endif