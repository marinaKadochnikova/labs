#include<iostream>
#include"BinaryTree.h"

using namespace std;

int main()
{
    BinaryTree intTree;
    int a;
    int b;
    int size;
    cout << " Tree size =  ";
    cin >> size;
    cout << size << " numbers  " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> a;
        intTree.Insert(a);
    }
    cout << "find element" << endl;
    cin >> b;
    cout << intTree.Search(b);
    return 0;
}