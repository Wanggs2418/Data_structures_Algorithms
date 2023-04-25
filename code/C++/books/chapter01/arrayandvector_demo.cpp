#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int seq_size = 8;
    int array_init[seq_size] = {
    1,2,3,4,
    5,6,7,8
};
    int array_demo[] = {
        10,11,12,
        13,14,15
    };
    // 获取数组长度
    // sizeof(array_demo) 表示整个数组所占的内存,sizeof(array_demo[0])表示第一个元素所占的内存。
    int demo = sizeof(array_demo) / sizeof(array_demo[0]);
    
    vector<int> vector_init(array_init, array_init + seq_size);
    
    cout << "hi"<<endl;
    cout <<"数组大小为:" << demo << endl;
    cout << "Vector大小为:" << vector_init.size() << endl;
    // cout << array_init[7];

}