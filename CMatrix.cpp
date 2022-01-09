/**
 * @Author: Wu Shaojin
 * @Email: wushaojin@hust.edu.cn
 * @Date: 2022-01-03 20:46:53
 * @Last Modified time: 2022-01-03 20:46:53
 * @Description: 2020
 * 
 */
#include <iostream>
using namespace std;

template <class T>
class Matrix2x2
{

public:
    Matrix2x2(T m11, T m12, T m21, T m22);
    Matrix2x2();

    Matrix2x2<T> &operator+=(Matrix2x2<T> &a);
    Matrix2x2<T> &operator+=(T a);
    Matrix2x2<T> &operator=(Matrix2x2<T> &a);

    void Print();

    T m[2][2];
};

template <class T>
Matrix2x2<T>::Matrix2x2(T m11, T m12, T m21, T m22)
{
    m[0][0] = m11;
    m[0][1] = m12;
    m[1][0] = m21;
    m[1][1] = m22;
}

template <class T>
void Matrix2x2<T>::Print()
{
    cout << "|" << m[0][0] << "," << m[0][1] << "|" << endl;
    cout << "|" << m[1][0] << "," << m[1][1] << "|" << endl;
}

template <class T>
Matrix2x2<T> &Matrix2x2<T>::operator+=(Matrix2x2<T> &a)
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            m[i][j] += a.m[i][j];
    return *this;
}
template <class T>
Matrix2x2<T> &Matrix2x2<T>::operator+=(T a)
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            m[i][j] += a;
    return *this;
}

template <class T>
Matrix2x2<T> &Matrix2x2<T>::operator=(Matrix2x2<T> &a)
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            this->m[i][j] = a.m[i][j];
    return *this;
}

int main()
{
    Matrix2x2<int> X(1, 2, 3, 4);
    Matrix2x2<int> Y(10, 20, 30, 40);
    cout << "X:,Y:" << endl;
    X.Print();
    Y.Print();

    X += Y;
    X.Print();

    X += 2;
    X.Print();

    X = Y;
    X.Print();
    return 0;
}