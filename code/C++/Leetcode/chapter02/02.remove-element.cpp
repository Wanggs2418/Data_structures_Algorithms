#include <iostream>
#include <vector>
using namespace std;

// 不使用额外的空间，删除数组中与给定的数相同的数值
//双指针方法
//时间复杂度：O(n);空间复杂度：O(1)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int before_index = 0;
        for (int after_index = 0; after_index < nums.size(); after_index++) {
            if (val != nums[after_index]) {
                nums[before_index++] = nums[after_index];
            }
        }
        return before_index;
    }

};

//双向指针，同向移动
class Solution01 {
public:
    int removeElement01(vector<int>& nums, int val){
        int left_index = 0;
        int right_index = nums.size() -1;
        while(left_index <= right_index) {
            // 直到找到相等的
            while(left_index <= right_index && nums[left_index] != val) {
                left_index++;
                // ++left_index;
            }
            // 直到找到不相等的
            while(left_index <= right_index && nums[right_index] == val) {
                right_index--;
                // --right_index;
            }
            if (left_index < right_index) {
                // nums[left_index++] = nums[right_index--];
                nums[left_index] = nums[right_index];
                left_index++;
                right_index--;
            }
        }
}
};

