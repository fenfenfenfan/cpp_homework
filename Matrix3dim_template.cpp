/*
Author:Wu Shaojin
*/
#include <iostream>
using namespace std;

/******************“ªŒ¨æÿ’Û******************/
template <typename T, int _size>
class Dynamic1Dim
{
public:
	Dynamic1Dim();
	~Dynamic1Dim();
	T &operator[](int index);

protected:
public:
	T *m_pBuf;
};

template <typename T, int _size>
Dynamic1Dim<T, _size>::Dynamic1Dim()
{
	m_pBuf = new T[_size];
}

template <typename T, int _size>
T &Dynamic1Dim<T, _size>::operator[](int index)
{
	return m_pBuf[index];
}

template <typename T, int _size>
Dynamic1Dim<T, _size>::~Dynamic1Dim()
{
	delete[] m_pBuf;
}

/******************∂˛Œ¨æÿ’Û******************/
template <typename T, int _m, int _n>
class Dynamic2Dim
{
public:
	Dynamic2Dim();
	~Dynamic2Dim();
	Dynamic1Dim<T, _n> &operator[](int index);

protected:
public:
	Dynamic1Dim<T, _n> *m_pBuf;
};

template <typename T, int _m, int _n>
Dynamic2Dim<T, _m, _n>::Dynamic2Dim()
{
	m_pBuf = new Dynamic1Dim<T, _n>[_m];
}

template <typename T, int _m, int _n>
Dynamic1Dim<T, _n> &Dynamic2Dim<T, _m, _n>::operator[](int index)
{

	return m_pBuf[index];
}

template <typename T, int _m, int _n>
Dynamic2Dim<T, _m, _n>::~Dynamic2Dim()
{
	for (int i = 0; i < _m; i++)
	{
		m_pBuf[i].~Dynamic1Dim();
	}
}

/******************»˝Œ¨æÿ’Û******************/
template <typename T, int _k, int _m, int _n>
class Dynamic3Dim
{
public:
	Dynamic3Dim();
	~Dynamic3Dim();
	Dynamic2Dim<T, _m, _n> &operator[](int index);
	Dynamic3Dim<T, _k, _m, _n> operator+(Dynamic3Dim &x);
	Dynamic3Dim<T, _k, _m, _n> &operator=(const Dynamic3Dim &x);

protected:
public:
	Dynamic2Dim<T, _m, _n> *m_pBuf;
};

template <typename T, int _k, int _m, int _n>
Dynamic3Dim<T, _k, _m, _n>::Dynamic3Dim()
{
	m_pBuf = new Dynamic2Dim<T, _m, _n>[_m];
}

//÷ÿ‘ÿ[]
template <typename T, int _k, int _m, int _n>
Dynamic2Dim<T, _m, _n> &Dynamic3Dim<T, _k, _m, _n>::operator[](int index)
{

	return m_pBuf[index];
}

//÷ÿ‘ÿ+
template <typename T, int _k, int _m, int _n>
Dynamic3Dim<T, _k, _m, _n> Dynamic3Dim<T, _k, _m, _n>::operator+(Dynamic3Dim &x)
{
	Dynamic3Dim temp;
	for (int k = 0; k < _k; k++)
	{
		for (int i = 0; i < _m; i++)
		{
			for (int j = 0; j < _n; j++)
			{
				temp.m_pBuf[k][i][j] = m_pBuf[k][i][j] + x.m_pBuf[k][i][j];
			}
		}
	}
	return temp;
}

//÷ÿ‘ÿ=
template <typename T, int _k, int _m, int _n>
Dynamic3Dim<T, _k, _m, _n> &Dynamic3Dim<T, _k, _m, _n>::operator=(const Dynamic3Dim &x)
{
	for (int k = 0; k < _k; k++)
	{
		for (int i = 0; i < _m; i++)
		{
			for (int j = 0; j < _n; j++)
			{
				(*this).m_pBuf[k][i][j] = x.m_pBuf[k][i][j];
			}
		}
	}
	return *this;
}

//Œˆππ
template <typename T, int _k, int _m, int _n>
Dynamic3Dim<T, _k, _m, _n>::~Dynamic3Dim()
{
	for (int i = 0; i < _m; i++)
	{
		m_pBuf[i].~Dynamic2Dim();
	}
}

/******************≤‚ ‘******************/
int main()
{
	typedef int TYPE1;
	TYPE1 a;

	Dynamic3Dim<TYPE1, 2, 5, 5> Matrix1;
	cout << "\n Dynamic3Dim<TYPE1,2,5,5> Matrix1" << endl;
	for (int k0 = 0; k0 < 2; k0++)
	{
		cout << "layer:" << k0 << endl;
		for (int i0 = 0; i0 < 5; i0++)
		{
			for (int j0 = 0; j0 < 5; j0++)
			{
				Matrix1[k0][i0][j0] = k0 * 25 + i0 * 5 + j0;
				a = Matrix1[k0][i0][j0];
				cout << a << ", ";
			}
			cout << endl;
		}
	}

	Dynamic3Dim<TYPE1, 2, 5, 5> Matrix2;
	cout << "\n Dynamic3Dim<TYPE1,2,5,5> Matrix2" << endl;
	for (int k0 = 0; k0 < 2; k0++)
	{
		cout << "layer:" << k0 << endl;
		for (int i0 = 0; i0 < 5; i0++)
		{
			for (int j0 = 0; j0 < 5; j0++)
			{
				Matrix2[k0][i0][j0] = 1;
				a = Matrix2[k0][i0][j0];
				cout << a << ", ";
			}
			cout << endl;
		}
	}
	Dynamic3Dim<TYPE1, 2, 5, 5> Matrix3;
	cout << "\nMatrix3 = Matrix1:" << endl;
	Matrix3 = Matrix1;
	for (int k0 = 0; k0 < 2; k0++)
	{
		cout << "layer:" << k0 << endl;
		for (int i0 = 0; i0 < 5; i0++)
		{
			for (int j0 = 0; j0 < 5; j0++)
			{
				a = Matrix3[k0][i0][j0];
				cout << a << ", ";
			}
			cout << endl;
		}
	}
	Dynamic3Dim<TYPE1, 2, 5, 5> Matrix4;
	cout << "\nMatrix3 = Matrix2+Matrix1:" << endl;
	Matrix4 = Matrix2 + Matrix1;
	for (int k0 = 0; k0 < 2; k0++)
	{
		cout << "layer:" << k0 << endl;
		for (int i0 = 0; i0 < 5; i0++)
		{
			for (int j0 = 0; j0 < 5; j0++)
			{
				a = Matrix4[k0][i0][j0];
				cout << a << ", ";
			}
			cout << endl;
		}
	}
	// system("PAUSE");
	return 0;
}
