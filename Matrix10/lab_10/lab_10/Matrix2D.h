#pragma once
#include "MatrixBase.h"
#include <iostream>

class Matrix2D :public MatrixBase
{
public:
    Matrix2D();
    static const unsigned int m_size = 2;
    int M[m_size][m_size];
};