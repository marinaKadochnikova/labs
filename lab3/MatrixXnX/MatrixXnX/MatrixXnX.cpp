#include <iostream>
#include<cstdlib> 

using namespace std;

class matrixXnX {

    int** M;
    int size;

public:
    matrixXnX()
    {
        M = NULL;
        size = 0;
    }

    matrixXnX(const int iDim)
    {
        size = iDim;
        M = new int* [size];
        for (int i = 0; i < size; ++i)
        {
            M[i] = new int[size];
            for (int j = 0; j < size; ++j)
                M[i][j] = 0;
        }
    }

    int element(const int i, const int j) const
    {
        if (size > 0)
            return M[i][j];
        else
            return 0;
    }
    void setElement(const int i, const int j, const int value)
    {
        if ((i < 0) || (i >= size))
            return;
        if ((j < 0) || (j >= size))
            return;
        M[i][j] = value;
    }

    void fillRandomElements(const int minVal, const int maxVal)
    {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                M[i][j] = rand() % (minVal - maxVal) - maxVal;
    }

    int sumPrincipalDiag()const
    {
        int i, j;
        int sum = 0;
        for (i = 0, j = 0; i < size; i++, j++)
            sum += M[i][j];
        return sum;
    }

    int sumSecondaryDiag()const
    {
        int sum = 0;
        int i, j;
        for (i = 0, j = size - 1; i < size; i++, j--)
            sum += M[i][j];
        return sum;
    }

    int productPrincipalDiag()const
    {
        int i, j;
        int product = 1;
        for (i = 0, j = 0; i < size; i++, j++)
            product *= M[i][j];
        return product;
    }

    int productSecondaryDiag()const
    {
        int i, j;
        int product = 1;
        for (i = 0, j = size - 1; i < size; i++, j--)
            product *= M[i][j];
        return product;
    }

    int sumRow(const int iRow) const
    {
        int sum = 0;
        for (int j = 0; j < size; j++)
            sum += M[iRow][j];
        return sum;
    }

    int minColumn(const int iCol) const
    {
        int min = M[0][0];
        for (int i = 0; i < size; i++)
            if (M[i][iCol] < min)
                min = M[i][iCol];
        return min;
    }

    int maxColumn(const int iCol)const
    {
        int max = M[0][0];
        for (int i = 0; i < size; i++)
            if (M[i][iCol] > max)
                max = M[i][iCol];
        return max;
    }

    void print()
    {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++)
                cout << M[i][j] << '\t';
            cout << '\n';
        }
        cout << '\n';

        for (int i = 0; i < size; i++)
            cout << "sum row " << i + 1 << " = " << sumRow(i) << '\n';
        cout << '\n';
        for (int i = 0; i < size; i++)
            cout << "min column " << i + 1 << " = " << minColumn(i) << '\n';
        cout << '\n';

        for (int i = 0; i < size; i++)
            cout << "max column " << i + 1 << " = " << maxColumn(i) << '\n';
        cout << '\n';

        cout << "sum principial diag = " << sumPrincipalDiag() << '\n';

        cout << "sum secondary diag = " << sumSecondaryDiag() << '\n';

        cout << "product pruncipal diag = " << productPrincipalDiag() << '\n';

        cout << "product secondary diag = " << productSecondaryDiag() << '\n';
    }

};

int main()
{
    matrixXnX a(4);
    a.fillRandomElements(-10, 9);
    a.print();
    return 0;
}