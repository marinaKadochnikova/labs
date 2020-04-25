// Search.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>

using namespace std;

int fillRandomElements(int, int);
int Search(int);

const unsigned int N = 10000;
const int limit = 100;
int Array[N];

int main()
{
    int value = 0;
    clock_t start, end;

    for (int i = 0; i < N; i++)
        Array[i] = fillRandomElements(-limit, limit);

    cout << "find element" << endl;
    cin >> value;

    start = clock();
    cout << "index = " << Search(value) << endl;
    end = clock();

    printf("Search element in unsorted was executed in %.4f second(s)\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));

}

int fillRandomElements(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int Search(int value)
{
    int index = -1;
    for (int i = 0; i < N; i++)
    {
        if (Array[i] == value)
            index = i;
    }
    return index;
}
