#include <iostream>
#include<cstdlib> 
using namespace std;

class matrix3x3 {
    int matrix[3][3];
    int size;

public:
    matrix3x3()
    {
        size = 3;
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                matrix[i][j] = 0;
    }
    int element(const int i, const int j) const
    {
        if (size > 0)
            return matrix[i][j];
        else return 0;
    }

    void setElement(const int i, const int j, const int value)
    {
        if ((i < 0) || (i >= size))
            return;
        if ((j < 0) || (j >= size))
            return;
        matrix[i][j] = value;
    }

    void fillRandomElements(const int minVal, const int maxVal)
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                matrix[i][j] = rand() % (minVal - maxVal) - maxVal;
    }
    void Print()
    {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                cout << matrix[i][j] << '\t';
            cout << '\n';
        }
    }

    int sumPrincipalDiag()const
    {
        int i, j;
        int sum = 0;
        for (i = 0, j = 0; i < 3; i++, j++)
            sum += matrix[i][j];
        return sum;
    }

    int sumSecondaryDiag()const
    {
        int sum = 0;
        int i, j;
        for (i = 0, j = 2; i < 3; i++, j--)
            sum += matrix[i][j];
        return sum;
    }

    int productPrincipalDiag()const
    {
        int i, j;
        int product = 1;
        for (i = 0, j = 0; i < 3; i++, j++)
            product *= matrix[i][j];
        return product;
    }

    int productSecondaryDiag()const
    {
        int i, j;
        int product = 1;
        for (i = 0, j = 2; i < 3; i++, j--)
            product *= matrix[i][j];
        return product;
    }

    int sumRow(const int iRow)const
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
            sum += matrix[iRow][j];
        return sum;
    }

    int minColumn(const int iCol) const
    {
        int min = matrix[0][0];
        for (int i = 0; i < 3; i++)
            if (matrix[i][iCol] < min)
                min = matrix[i][iCol];
        return min;
    }

    int maxColumn(const int iCol)const
    {
        int max = matrix[0][0];
        for (int i = 0; i < 3; i++)
            if (matrix[i][iCol] > max)
                max = matrix[i][iCol];
        return max;
    }
};


int main()
{
    matrix3x3 a;
    a.fillRandomElements(-10, 9);
    a.Print();
    for (int i = 0; i < 3; i++)
        cout << "sum row " << i + 1 << " = " << a.sumRow(i) << '\n';

    cout << '\n';

    for (int i = 0; i < 3; i++)
        cout << "min column " << i + 1 << " = " << a.minColumn(i) << '\n';

    cout << '\n';

    for (int i = 0; i < 3; i++)
        cout << "max column " << i + 1 << " = " << a.maxColumn(i) << '\n';

    cout << '\n';

    cout << "sum principial diag = " << a.sumPrincipalDiag() << '\n';

    cout << "sum secondary diag = " << a.sumSecondaryDiag() << '\n';

    cout << '\n';

    cout << "product pruncipal diag = " << a.productPrincipalDiag() << '\n';

    cout << "product secondary diag = " << a.productSecondaryDiag() << '\n';

    return 0;
}