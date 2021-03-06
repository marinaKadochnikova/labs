﻿// QuickSort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>


using namespace std;

int fillRandomElements(int, int);
void QuickSort(int*, int, int);
void RQuickSort(int*, int, int);
int BSearch(int, int[], int, int);
int RBSearch(int, int[], int, int);
void Print();

const unsigned int N = 100;
const int limit = 10;
int Array[N];

int main()
{

    int value = 0;
    int key = 0;
    int index = 0;
    int* begin = std::begin(Array);

    clock_t start, end;

    for (int i = 0; i < N; i++)
        Array[i] = fillRandomElements(-limit, limit);

    Print();

    QuickSort(begin, 0, N - 1);

    Print();

    cout << "find element Binary Search" << endl;
    cin >> key;

    start = clock();
    index = RBSearch(key, Array, 0, N);
    end = clock();

    printf("Search for an element in sorted Array was executed in %.4f second(s)\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));

    cout << "element = " << key << " index = " << index << "\n\n";

    return 0;
}

void Print()
{
    for (int i = 0; i < 50; i++)
        cout << Array[i] << endl;
    cout << endl;
}

int fillRandomElements(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void QuickSort(int* begin, int first, int last)
{
    int i, j;
    int lb, rb;  		// границы сортируемого в цикле фрагмента
    int lbStack[N], rbStack[N];

    int stackpos = 1;
    int indexBase;
    int base;
    int temp;

    lbStack[1] = first;
    rbStack[1] = last;

    while (stackpos != 0)
    {
        lb = lbStack[stackpos];
        rb = rbStack[stackpos];
        stackpos--;

        while (lb < rb)
        {
            indexBase = (lb + rb) / 2;
            base = begin[indexBase];
            i = lb;
            j = rb;


            while (i <= j)
            {
                while (begin[i] < base) i++;
                while (begin[j] > base) j--;

                if (i <= j)
                {
                    temp = begin[i];
                    begin[i] = begin[j];
                    begin[j] = temp;
                    i++; j--;
                }
            }

            if (i < indexBase)      // правая часть больше
            {

                if (i < rb)         //  если в ней больше 1 элемента - нужно
                {
                    stackpos++;
                    lbStack[stackpos] = i;
                    rbStack[stackpos] = rb;
                }
                rb = j;
            }
            else                    // левая часть больше
            {
                if (j > lb)
                {
                    stackpos++;
                    lbStack[stackpos] = lb;
                    rbStack[stackpos] = j;
                }
                lb = i;
            }
        }
    }
}

void RQuickSort(int* begin, int first, int last)
{
    int i = first;
    int j = last;
    int tmp;
    int x = begin[(first + last) / 2];

    while (i <= j)
    {
        while ((begin[i] < x) && (i < last))
            i++;
        while ((begin[j] > x) && (j > first))
            j--;

        if (i <= j)
        {
            tmp = begin[i];
            begin[i] = begin[j];
            begin[j] = tmp;
            i++;
            j--;
        }
    }

    if (i < last)
        QuickSort(begin, i, last);
    if (first < j)
        QuickSort(begin, first, j);
}

int BSearch(int key, int Array[], int left, int right)
{
    int mid = 0;
    while (1)
    {
        if (left > right)
            return -1;
        mid = (left + right) / 2;
        if (key < Array[mid])
            right = mid - 1;
        else
            if (key > Array[mid])
                left = mid + 1;
            else
                return mid;
    }
}

int RBSearch(int key, int Array[], int left, int right)
{
    if (right < left)
        return -1;
    int mid = (left + right) / 2;

    if (key < Array[mid])
        RBSearch(key, Array, left, mid - 1);
    else
        if (key > Array[mid])
            RBSearch(key, Array, mid + 1, right);
        else
            return mid;
}
