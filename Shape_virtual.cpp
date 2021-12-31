/**
 * @Author: Wu Shaojin
 * @Email: wushaojin@hust.edu.cn
 * @Date: 2021-12-31 13:02:27
 * @Last Modified time: 2021-12-31 13:02:27
 * @Description: virtual class Shape
 * 
 */
#include <iostream>
using namespace std;

class Shape
{
public:
    virtual float mianji() = 0;
};

class Square : public Shape
{
private:
    float m_a, m_h;

public:
    Square(float a, float h) : m_a(a), m_h(h) {}
    float mianji()
    {
        return m_a * m_h;
    }
};

class Trapezoid : public Shape
{
private:
    float m_a, m_h, m_b;

public:
    Trapezoid(float a, float h, float b) : m_a(a), m_h(h), m_b(b) {}
    float mianji()
    {
        return 0.5 * (m_a + m_b) * m_h;
    }
};

class Triangle : public Shape
{
private:
    float m_a, m_h;

public:
    Triangle(float a, float h) : m_a(a), m_h(h) {}
    float mianji()
    {
        return 0.5 * m_a * m_h;
    }
};

float get_mianji(Shape *x)
{
    return x->mianji();
}

int main()
{
    Shape *p[3];

    Square square(3, 3);          // 9
    Trapezoid trapezoid(2, 3, 4); // 9
    Triangle triangle(3, 6);      // 9
    p[0] = &square;
    p[1] = &trapezoid;
    p[2] = &triangle;

    // p[0] = new Square(3, 3);
    // p[1] = new Trapezoid(2, 3, 4);
    // p[2] = new Triangle(3, 6);

    float a, b, c;
    a = get_mianji(p[0]);
    b = get_mianji(p[1]);
    c = get_mianji(p[2]);
    cout << "正方形、梯形、三角形面积分别为：";
    cout << a << " " << b << " " << c << endl;
    cout << "面积和为：" << a + b + c << endl;

    // system("pause");
    // delete p[0], p[1], p[2];
    return 0;
}