#pragma once
#include<iostream>

class MatrixBase
{
public:
    unsigned int size() const;
    void setElement(unsigned int i, unsigned int j, int value);
    virtual int element(unsigned int i, unsigned int j) const;
    virtual int& element(unsigned int i, unsigned int j);
    void fillElement();
    virtual void operator*=(int iMult);
    virtual void operator+=(MatrixBase iAdd);
protected:
    MatrixBase(unsigned int iSize) :m_size(iSize) {};
private:
    const unsigned int m_size;
    static const int N = 5;
    int M[N][N];
};

std::ostream& operator<<(std::ostream& stream, const MatrixBase& iMatrix);