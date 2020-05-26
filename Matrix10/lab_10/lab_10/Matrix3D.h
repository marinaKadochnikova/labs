#pragma once
#include "MatrixBase.h"
#include <iostream>

class Matrix3D :public MatrixBase
{
public:
    Matrix3D();
    static const unsigned int m_size = 3;
    int M[m_size][m_size];
};
