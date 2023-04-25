#include <iostream>
#include <vector>
using namespace std;

// 二分法，[left, right]
//应用前提：数组为有序数组，且无重复的元素
class BinarySearch {
public:
    int search(vector<int>& nums, int target) {
        int num_index = nums.size() - 1;
        if (target < nums[0] || target > nums[num_index]) {
            return -1;
        }
        
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            int mid = left + ((right - left) / 2);
            if (nums[mid] > target) {
                right = mid - 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else if (nums[mid] = target) {
                return mid;
            }
        }
        // 未找到目标值
        return -1;
    }
};