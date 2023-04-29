#include <vector>
#include <string>
using namespace std;

class Stack
{
private:
    vector<string> _stack;
public:
// 仅声明
    bool pop(string &elem);
    bool empty();
};

// Stack::empty() 表明 empty 是 Stack class 中的一个 member,:: 表示类作用域解析运算符(class scope resolution)
inline bool
Stack::empty()
{
    return _stack.empty();
}

bool
Stack::pop(string &elem){
    if (empty())
        return false;
    elem = _stack.back();
    _stack.pop_back();
    return true;
}

class  Triangular {
public:
    // 构造函数，重载操作
    Triangular(); //默认的情况
    Triangular(int len);
    Triangular(int len = 1, int beg_pos = 1);
private:
    int _length;
    int _beg_pos;
    int _next;
};

// 带默认值
Triangular::Triangular(int len, int bp)
{
    _length = len > 0 ? len : 1;
    _beg_pos = bp > 0 ? bp : 1;
    _next = _beg_pos - 1;
};
// 另一种初始化方法：成员初始化列表
Triangular::Triangular(const Triangular &rhs) : _length(rhs._length), _beg_pos(rhs._beg_pos), _next(rhs._beg_pos -1) {}


class Matrix {
public:
    Matrix(int row, int col) : _row(row), _col(col){
        _pmat = new double[row * col]; //定义元素类型为 double 的数组
    }

    ~Matrix()
    {
        //destructor进行资源分配
        delete [] _pmat;
    }
private:
    int _row, _col;
    double* _pmat;
};
