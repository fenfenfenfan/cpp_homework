/**
 * @Author: Wu Shaojin
 * @Email: wushaojin@hust.edu.cn
 * @Date: 2022-01-03 17:08:23
 * @Last Modified time: 2022-01-03 17:08:23
 * @Description: 建立一个字符串用来存储和处理字符串，采用成员函数对操作符‘+’进行重载，以实现两个字符串的合并功能
 * 
 */
#include <iostream>
#include <string.h>
using namespace std;

class str
{
public:
    str(const char *s);
    // void operator+(str &x);
    void show();
    friend void operator+(str &x, str &y);

private:
    char string[80];
};

str::str(const char *s)
{
    strcpy(string, s);
}
// void str::operator+(str &x)
// {
//     strcat(string, x.string);
// }
void str::show()
{
    cout << string << endl;
}

void operator+(str &x, str &y)
{
    strcat(x.string, y.string);
}

int main()
{
    str s1("hello");
    str s2("world");
    s1.show();
    s2.show();
    cout << "s1+s2:" << endl;
    s1 + s2;
    s1.show();
    return 0;
}