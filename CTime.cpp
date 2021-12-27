/*
Author:Wu Shaojin
*/
#include <iostream>
using namespace std;

class CTime
{
public:
    CTime();
    CTime(int year, int month, int day) : m_year(year), m_month(month), m_day(day) {}
    CTime operator+(CTime &x);
    CTime operator+=(CTime &x);
    CTime operator=(const CTime &x);
    void show_time();

private:
    int m_year, m_month, m_day;
};

CTime::CTime()
{
    m_day = 0;
    m_month = 0;
    m_year = 0;
}

CTime CTime::operator+(CTime &x)
{
    CTime temp;
    int flag_d = 0; //标志位
    int flag_m = 0;
    if ((m_day + x.m_day) % 30 == 0)
    {
        flag_d = (m_day + x.m_day) / 30 - 1;
        temp.m_day = 30;
    }
    else
    {
        flag_d = (m_day + x.m_day) / 30;
        temp.m_day = (m_day + x.m_day) % 30;
    }
    if ((m_month + x.m_month + flag_d) % 12 == 0)
    {
        flag_m = (m_month + x.m_month + flag_d) / 12 - 1;
        temp.m_month = 12;
    }
    else
    {
        flag_m = (m_month + x.m_month + flag_d) / 12;
        temp.m_month = (m_month + x.m_month + flag_d) % 12;
    }
    temp.m_year = m_year + x.m_year + flag_m;
    return temp;
}

CTime CTime::operator+=(CTime &x)
{
    CTime temp;
    int flag_d = 0; //标志位
    int flag_m = 0;
    if ((m_day + x.m_day) % 30 == 0)
    {
        flag_d = (m_day + x.m_day) / 30 - 1;
        temp.m_day = 30;
    }
    else
    {
        flag_d = (m_day + x.m_day) / 30;
        temp.m_day = (m_day + x.m_day) % 30;
    }
    if ((m_month + x.m_month + flag_d) % 12 == 0)
    {
        flag_m = (m_month + x.m_month + flag_d) / 12 - 1;
        temp.m_month = 12;
    }
    else
    {
        flag_m = (m_month + x.m_month + flag_d) / 12;
        temp.m_month = (m_month + x.m_month + flag_d) % 12;
    }
    temp.m_year = m_year + x.m_year + flag_m;
    this->m_day = temp.m_day;
    this->m_month = temp.m_month;
    this->m_year = temp.m_year;
    return *this;
}

CTime CTime::operator=(const CTime &x)
{
    this->m_year = x.m_year;
    this->m_month = x.m_month;
    this->m_day = x.m_day;
    return *this;
}

void CTime::show_time()
{
    cout << m_year << "年" << m_month << "月" << m_day << "日\n"
         << endl;
}

int main()
{
    CTime time1(2021, 10, 1);
    CTime time2(0, 0, 90);
    CTime time3;
    cout << "time1" << endl;
    time1.show_time();
    cout << "time2" << endl;
    time2.show_time();

    time3 = time1;
    cout << "time3 = time1:" << endl;
    time3.show_time();

    time3 = time1 + time2;
    cout << "time3 = time1 + time2:" << endl;
    time3.show_time();

    time1 += time2;
    cout << "time1 += time2:" << endl;
    time1.show_time();
    return 0;
}