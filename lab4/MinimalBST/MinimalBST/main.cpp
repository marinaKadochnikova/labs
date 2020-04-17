#include<iostream>
#include"BinaryTree.h"

using namespace std;

int main()
{
    BinaryTree intTree;
    int lenght = 5;
    int* numbers = new int[lenght] { 1, 2, 3, 4, 5 };
    int start = 0;
    int end = lenght - 1;
    intTree.CreateMinimalBST(numbers, start, end);
    int b;
    cout << "find element ";
    cin >> b;
    intTree.Search(b);
    return 0;
}