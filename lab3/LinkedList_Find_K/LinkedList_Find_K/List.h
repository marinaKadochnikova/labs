#ifndef LIST_H
#define LIST_H

#include"Node.h"

class List
{
public:
	List();
	~List();
	void push_back(int data);
	int findElement(int k);
	void printList();
	void removeDub();

private:
	friend class Node;
	int Size;
	Node* head;
};
#endif 

