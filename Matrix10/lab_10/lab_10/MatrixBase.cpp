#include "MatrixBase.h"

unsigned int MatrixBase::size() const
{
    return m_size;
}

void MatrixBase::setElement(unsigned int i, unsigned int j, int value)
{
    M[i][j] = value;
}

int MatrixBase::element(unsigned int i, unsigned int j) const
{
    return M[i][j];
}

int& MatrixBase::element(unsigned int i, unsigned int j)
{
    return M[i][j];
}

void MatrixBase::fillElement()
{
    int value = 1;
    for (unsigned int i = 0; i < m_size; i++)
        for (unsigned int j = 0; j < m_size; j++)
            M[i][j] = value++;
}

void MatrixBase::operator*=(int iMult)
{
    for (unsigned int i = 0; i < m_size; i++)
        for (unsigned int j = 0; j < m_size; j++)
            M[i][j] *= iMult;
}

void MatrixBase::operator+=(MatrixBase iAdd)
{
    for (unsigned int i = 0; i < iAdd.m_size; i++)
        for (unsigned int j = 0; j < iAdd.m_size; j++)
            M[i][j] += iAdd.M[i][j];
}

std::ostream& operator<<(std::ostream& stream, const MatrixBase& iMatrix)
{
    for (unsigned int i = 0; i < iMatrix.size(); i++)
    {
        for (unsigned int j = 0; j < iMatrix.size(); j++)
            stream << iMatrix.element(i, j) << ' ';
        stream << '\n';
    }
    return stream;
}