#include <iostream>
using namespace std;

// 斐波那契数列的实现，两次递归会导致时间复杂度呈指数上升O(2^n)
int fabonacci(int i) {
    if (i == 0) return 0;
    if (i == 1) return 1;
    return fabonacci(i-1) + fabonacci(i-2);
}
//改进的方法，时间复杂度为O(n)
int fabonacci_m(int i, int first = 1, int second = 1) {
    if (i == 0) return 0;
    if (i < 3) return 1;
    if (i == 3) {
        return first + second;
    }
    else {
        return fabonacci_m(i-1, second, first + second);
    }
    
}

int main() {
    int demo;
    demo = fabonacci(10);
    cout << demo << endl;
}