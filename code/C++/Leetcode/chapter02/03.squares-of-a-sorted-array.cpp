#include <iostream>
#include <vector>
using namespace std;

// 要求时间复杂度为O(n)
// 双指针写法
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int array_size = nums.size();
        int index = array_size - 1;
        int right = index;

        vector<int> result(array_size, 0);
        for (int left =0; left <= right;){
            if(nums[left] * nums[left] >= nums[right] * nums[right]){
                result[index] = nums[left] * nums[left];
                left++;
            }
            else{
                result[index] = nums[right] * nums[right];
                right--;
            }
            index--;
        }
        return result;
    }
};