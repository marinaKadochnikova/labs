#include<iostream>
#include"BinaryTree.h"

using namespace std;

int main()
{
    BinaryTree intTree;
    int lenght = 5;
    int* numbers = new int[lenght] { 1, 2, 3, 4, 5 };
    intTree.CreateMinimalBST(numbers, 0, lenght - 1);
    int b;
    cout << "find element ";
    cin >> b;
    cout << intTree.Search(b);
    return 0;
}