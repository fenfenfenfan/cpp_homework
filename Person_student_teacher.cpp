/**
 * @Author: Wu Shaojin
 * @Email: wushaojin@hust.edu.cn
 * @Date: 2022-01-03 17:10:39
 * @Last Modified time: 2022-01-03 17:10:39
 * @Description: 写一个具有动态多态性的学生和教师信息输入和显示程序，学生数据有编号、姓名、班号和成绩，教师数据有编号、姓名、职称和部门。
 * 要求将编号、姓名、输入和显示设计成一个抽象类person的成员，并将person类作为学生数据操作类student和教师操作类teacher的基类。程序应能根据
 * 待输入人员的类别完成对应人员信息的输入和显示功能。
 * 
 */
#include <iostream>
#include <string.h>
using namespace std;

class person
{
public:
    virtual void input() = 0;
    virtual void display() = 0;

    int num;
    char name[20];
};

class student : public person
{
public:
    virtual void input()
    {
        cout << "请依次输入学生的编号、姓名、班号和成绩：" << endl;
        cin >> num >> name >> class_num >> score;
    }
    virtual void display()
    {
        cout << "学生的编号、姓名、班号和成绩分别为：" << num << "," << name << "," << class_num << "," << score << endl;
    }

private:
    int class_num;
    float score;
};

class teacher : public person
{
public:
    virtual void input()
    {
        cout << "请依次输入老师的编号、姓名、职称和部门：" << endl;
        cin >> num >> name >> title >> department;
    }
    virtual void display()
    {
        cout << "老师的编号、姓名、职称和部门分别为：" << num << "," << name << "," << title << "," << department << endl;
    }

private:
    char title[20];
    char department[20];
};

int main()
{
    student s1;
    teacher t1;
    s1.input();
    t1.input();
    s1.display();
    t1.display();
    return 0;
}
/*
请依次输入学生的编号、姓名、班号和成绩：
1 zhangsan 2021 99
请依次输入老师的编号、姓名、职称和部门：
1 lisi doctor 办公室
学生的编号、姓名、班号和成绩分别为：1,zhangsan,2021,99
老师的编号、姓名、职称和部门分别为：1,lisi,doctor,办公室
*/