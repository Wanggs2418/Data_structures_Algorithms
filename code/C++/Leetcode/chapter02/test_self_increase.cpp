#include <iostream>
using namespace std;

int main() {
    // int i = 0;
    // while (i < 10) {
        // i++;
        // ++i;
        // cout << i <<endl;
    // }

// 前置形式,prefix
// 先递减or递增,之后再使用
// 输出结果为 1
    int tries = 0;
    int tries_again = 0;
    cout << "try it！"
         << ++tries <<'\n';

// 先使用在递增  
    cout << "try it again！"
         << tries_again++ << '\n';
}