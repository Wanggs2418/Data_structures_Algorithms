#include <iostream>
using namespace std;

// 求 x 的 n 次方 O(logn)
int function1(int x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;
    int temp = function1(x, n / 2);
    if (n / 2 == 1) {
        return temp * temp * x;
    }
    return temp * temp;
}

int main() {
    long long results;
    results = function1(5, 10);
    cout << results << endl;
}

