#ifndef BINARYTREE_H
#define BINARYTREE_H

#include"TreeNode.h"

class BinaryTree
{
    TreeNode* root;
    void Insert(TreeNode* n, const int& val);
    TreeNode* Search(TreeNode* n, const int& val);

public:
    BinaryTree();
    ~BinaryTree();
    void Destoy(TreeNode* node);
    void Insert(const int& x);
    TreeNode* Search(const int& val);
    TreeNode* GetRoot() { return root; }
};
#endif