#include <iostream>
using namespace std;


template< typename T>
class List
{
public:
	List();
	~List();

	void push_back(T data);

	int GetSize() { return Size; }

	void printList();

	void removeDub();

private:

	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T>* head;
};


template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}


template<typename T>
List<T>::~List()
{
	while (Size)
	{
		Node<T>* temp = head;

		head = head->pNext;

		delete temp;

		Size--;
	}
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template<typename T>
void List<T>::printList()
{
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		cout << current->data << endl;
		current = current->pNext;
	}
}

template<typename T>
void List<T>::removeDub()
{
	if (head == nullptr) return;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		Node<T>* runner = current;
		while (runner->pNext != nullptr)
			if (runner->pNext->data == current->data)
			{
				Node<T>* toDelete = runner->pNext;

				runner->pNext = toDelete->pNext;

				delete toDelete;
				Size--;
			}
			else
				runner = runner->pNext;
		current = current->pNext;
	}
}

int main()
{
	List<int> lst;
	lst.push_back(5);
	lst.push_back(2);
	lst.push_back(1);
	lst.push_back(3);
	lst.push_back(2);
	lst.push_back(2);
	lst.push_back(3);

	lst.printList();

	cout << endl << "Remove Dublicates " << endl << endl;

	lst.removeDub();

	lst.printList();

	cout << endl;

	lst.~List();

	return 0;
}
