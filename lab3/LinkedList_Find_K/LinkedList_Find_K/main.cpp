#include <iostream>
#include"List.h"
using namespace std;


int main()
{
	List lst;
	lst.push_back(2);
	lst.push_back(2);
	lst.push_back(6);
	lst.push_back(5);
	lst.push_back(4);
	lst.push_back(1);
	lst.push_back(8);
	lst.push_back(8);
	lst.push_back(7);

	lst.printList();
	cout << endl << "Remove Dublicates " << endl << endl;
	lst.removeDub();
	lst.printList();

	int k = 0;
	cout << endl << "which element from the end do you want to find " << endl << endl;
	cin >> k;
	cout << endl << "element = " << lst.findElement(k);

	lst.~List();
	return 0;
}