#include<iostream>
#include"Matrix2D.h"
#include"Matrix3D.h"

using namespace std;

int main()
{
    Matrix2D m2a, m2b;
    Matrix3D m3a, m3b;
    int k = 3;

    m2a.fillElement();
    m2b.fillElement();
    m3a.fillElement();
    m3b.fillElement();

    cout << m2a << endl;
    cout << m2b << endl;
    cout << m3a << endl;
    cout << m3b << endl;

    cout << "matrix multiplication by number = " << k << endl;
    m2a.operator*=(k);
    m2b.operator*=(k);
    m3a.operator*=(k);
    m3b.operator*=(k);

    cout << m2a << endl;
    cout << m2b << endl;
    cout << m3a << endl;
    cout << m3b << endl;

    cout << "Addition Matrix2D" << endl;
    m2a.operator+=(m2b);
    cout << m2a << endl;

    cout << "Addition Matrix3D" << endl;
    m3a.operator+=(m3b);
    cout << m3a << endl;

    return 0;
}