#include<iostream>
using namespace std;
int main()
{
    char s[10]="sjtu";
    cout << s; // 输出 sjtu,因为字符串末尾添加了空字符'\0'
    char t[10]={'s','j','t','u'};
    cout << t; // 这里输出不可预期，因为没有空字符结尾，cout可能会继续输出s后面的内存内容，直到遇到第一个'\0'
    return 0;
}