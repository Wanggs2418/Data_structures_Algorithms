#include <iostream>
using namespace std;

int main() {
    int a = 123;
    int array_b[] = {
        1,2,3
    };
    int *p = array_b;
    // int 类型对象的指针
    // *p_a 称为 dereference 操作
    int *p_a = &a;

    // 结果为8个16进制的数，即32位
    cout << "数组地址:" << p << endl;
    cout << "int 类型变量 a 为:" << a <<endl;
    cout << "a的地址为:"<< &a <<endl;
    cout <<"指针p_a:"<< p_a << endl;
    cout <<"*p_a为:" <<*p_a << endl;
}