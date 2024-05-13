#include<iostream>
using namespace std;

void quote(int &a)
{
    a = 10;
}

void addr(int *a)
{
    *a = 20;
}

void def4ult(int a, int b = 2, int c = 3)
{
    cout << a << " " << b << " " << c << endl;
}

void ar2ay(int a[], int length)
{
    cout << a[length-1] << endl;
}

void modifyArray(int (&arr)[5]) {
    for (int i = 0; i < 5; ++i) {
        arr[i] *= 2;
        cout << arr[i] << " ";
    }

}
int main()
{
    int t = 5;
    int a[5] = {1, 2, 3, 4, 5};
    quote(t);
    cout << t << endl;  // 10
    addr(&t);
    cout << t << endl;  // 20
    def4ult(1, 4);  // 1 4 3
    ar2ay(a, 5);    // 5
    modifyArray(a);
    return 0;
}