#include <iostream>
using namespace std;


template< typename T>
class List
{
public:
	List();
	~List();

	void push_back(T data);
	void findEl(int k);
	void printList();

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
void List<T>::findEl(int index)
{
	int counter = Size;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			cout << current->data;
		}
		current = current->pNext;
		counter--;
	}
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

int main()
{
	List<int> lst;
	lst.push_back(2);
	lst.push_back(9);
	lst.push_back(6);
	lst.push_back(5);

	lst.printList();

	int k = 0;
	cout << endl << "which element from the end do you want to find " << endl << endl;
	cin >> k;
	cout << endl << "element = ";
	lst.findEl(k);

	lst.~List();
	return 0;
}