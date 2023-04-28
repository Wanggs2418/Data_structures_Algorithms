#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX; //初始值定义为32位最大值
        int i = 0; //其实位置
        int sum = 0;
        int subLength = 0;

        for (int j = 0;j < nums.size();j++) {
            sum += nums[j];
            // 大于目标值，起始位置向前移动, 用wile而不是if
            while (sum >= target) {
                subLength = j - i + 1;
                result = result > subLength ? subLength:result;
                sum -= nums[i];
                i++;
            }
        }
        return result == INT32_MAX ? 0:result;
    }
};

int main() {
    Solution solv;
    int target = 7;
    int demo_array[6] = {
        2,3,1,2,4,3
    };
    
    vector<int> nums(demo_array, demo_array + 6);
    int temp = solv.minSubArrayLen(target, nums);
    cout <<"输出结果为:" << temp << endl;
}