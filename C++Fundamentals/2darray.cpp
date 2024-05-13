#include<iostream>
using namespace std;
int main()
{
    int a[][3] = {{1,2,3},{4},{5,6}};
    cout << a[1][2] << endl;    // 未初始化的元素都为0
    cout << *(a[1]) << endl;    // 4
    cout << *(a[2]+1) << endl;  // 6
    return 0;
}