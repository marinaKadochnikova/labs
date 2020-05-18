#include"List.h"
#include"Node.h"

#include <iostream>
using namespace std;

List::List()
{
	Size = 0;
	head = nullptr;
}

List::~List()
{
	while (Size)
	{
		Node* temp = head;
		head = head->pNext;
		delete temp;
		Size--;
	}
}

void List::push_back(int data)
{
	if (head == nullptr)
	{
		head = new Node(data);
	}
	else
	{
		Node* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node(data);
	}
	Size++;
}

int List::findElement(int index)
{
	int counter = Size;
	Node* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter--;
	}
}

void List::removeDub()
{
	if (head == nullptr) return;
	Node* current = this->head;
	while (current != nullptr)
	{
		Node* runner = current;
		while (runner->pNext != nullptr)
			if (runner->pNext->data == current->data)
			{
				Node* toDelete = runner->pNext;

				runner->pNext = toDelete->pNext;

				delete toDelete;
				Size--;
			}
			else
				runner = runner->pNext;
		current = current->pNext;
	}
}

void List::printList()
{
	Node* current = this->head;
	while (current != nullptr)
	{
		cout << current->data << endl;
		current = current->pNext;
	}
}