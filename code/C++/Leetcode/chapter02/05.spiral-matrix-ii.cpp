#include <iostream>
#include <vector>
using namespace std;

//螺旋矩阵，两次循环
class Solution{
public:
    // 返回值类型为二维的嵌套数组
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int startx = 0, starty = 0;
        // int loop = n % 2 ? n/2 +1 : n/2;
        int loop = n / 2;
        int mid = n / 2;
        int offset = 1; //n-offset控制每条边的遍历长度
        int count = 1;
        int i,j;

        while(loop --){
            i = startx;
            j = starty;

            // 行数不变
            for (i = startx; i < n - offset; i++) {
                res[startx][i] = count++;
            }
            // 列数不变
            for (j = starty; j < n - offset; j++) {
                res[j][i] = count++;
            }
            // 行数不变
            for (; i > startx; i--) {
                res[j][i] = count++;
            }
            for (; j > starty; j--) {
                res[j][i] = count++;
            }

            // 起始位置移动
            startx++;
            starty++;
            offset++;
        }
        if (n % 2){
            res[mid][mid] = count;
        }
        return res;
    }

};

int main() {
    // int num = 3 / 2;
    // cout << "num is" << num <<endl;
    
    Solution solv;
    int n = 10;
    // vector<vector<int>> res(solv.generateMatrix(3));
    vector<vector<int>> res = solv.generateMatrix(n);
    
    // cout << "vector is "<< res.size() << endl;

    for (int i = 0; i < n; i++){
        // cout <<"---"<<endl;
        for (int j = 0; j < n; j++){
            cout.width(4); //设置输出格式宽度
            cout << res[i][j] <<",";
            if (j == (n -1)){
                cout << endl;
            }
        }
    }

}