#ifndef NODE_H
#define NODE_H

class Node
{
public:
	Node* pNext;
	int data;
	Node(int data = 0, Node* pNext = nullptr);
};
#endif