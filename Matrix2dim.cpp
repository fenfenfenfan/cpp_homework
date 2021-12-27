/*
Author:Wu Shaojin
Data:2021年12月25日
*/
#include <iostream>
#include <stdio.h>

using namespace std;

class Matrix
{
public:
    Matrix();
    Matrix(int row, int col);
    ~Matrix();
    void Set_Matrix(int row, int col);
    void Input_Matrix();
    void Show_Matrix();
    Matrix operator+(Matrix &x);
    Matrix operator-(Matrix &x);
    Matrix operator*(Matrix &x);
    Matrix operator=(const Matrix &x);

private:
    int m_row;
    int m_col;
    int m_mat[10][10];
};
// 构造析构函数
Matrix::Matrix()
{
    m_row = 0;
    m_col = 0;
}

Matrix::Matrix(int row, int col) : m_row(row), m_col(col)
{
    int i, j;
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            m_mat[i][j] = 0;
}

Matrix::~Matrix() {}
// 定义矩阵
void Matrix::Set_Matrix(int row, int col)
{
    m_row = row;
    m_col = col;
}

void Matrix::Input_Matrix()
{
    int i, j;
    for (i = 0; i < m_row; i++)
    {
        printf("输入第%d行:\n", i + 1);
        for (j = 0; j < m_col; j++)
        {
            cin >> m_mat[i][j];
        }
    }
}

void Matrix::Show_Matrix()
{
    int i, j;
    for (i = 0; i < m_row; i++)
    {
        for (j = 0; j < m_col; j++)
        {
            cout << m_mat[i][j] << " ";
        }
        cout << endl;
    }
}
// 运算符重载
Matrix Matrix::operator+(Matrix &x)
{
    Matrix temp(m_row, m_col);
    int i, j;
    for (i = 0; i < m_row; i++)
    {
        for (j = 0; j < m_col; j++)
        {
            temp.m_mat[i][j] = m_mat[i][j] + x.m_mat[i][j];
        }
    }
    return temp;
}

Matrix Matrix::operator-(Matrix &x)
{
    Matrix temp(m_row, m_col);
    int i, j;
    for (i = 0; i < m_row; i++)
    {
        for (j = 0; j < m_col; j++)
        {
            temp.m_mat[i][j] = m_mat[i][j] - x.m_mat[i][j];
        }
    }
    return temp;
}

Matrix Matrix::operator*(Matrix &x)
{
    Matrix temp(m_row, m_col);
    int i, j, k;
    for (i = 0; i < m_row; i++)
    {
        for (j = 0; j < m_col; j++)
        {
            for (k = 0; k < m_col; k++)
            {
                temp.m_mat[i][j] = m_mat[i][k] * x.m_mat[k][j] + temp.m_mat[i][j];
            }
        }
    }
    return temp;
}

Matrix Matrix::operator=(const Matrix &x)
{
    int i, j;
    for (i = 0; i < m_row; i++)
    {
        for (j = 0; j < m_col; j++)
        {
            this->m_mat[i][j] = x.m_mat[i][j];
        }
    }
    return *this;
}

int main()
{
    Matrix m1, m2, m3;
    int i1, i2, j1, j2;
    cout << "请输入第一个矩阵的行和列：" << endl;
    cin >> i1 >> j1;
    m1.Set_Matrix(i1, j1);
    cout << "输入第一个矩阵：" << endl;
    m1.Input_Matrix();
    cout << "第一个矩阵为：" << endl;
    m1.Show_Matrix();

    cout << "请输入第二个矩阵的行和列：" << endl;
    cin >> i2 >> j2;
    m2.Set_Matrix(i2, j2);
    cout << "输入第二个矩阵：" << endl;
    m2.Input_Matrix();
    cout << "第二个矩阵为：" << endl;
    m2.Show_Matrix();

    m3.Set_Matrix(i1, j2);
    m3 = m1 * m2;
    cout << "m1*m2=m3" << endl;
    m3.Show_Matrix();

    return 0;
}