/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            if (nums.at(left) < nums.at(right)) return nums.at(left);

            int mid = (left + right) / 2;
            if (nums.at(mid) >= nums.at(left)) left = mid + 1;
            else  right = mid;
        }

        return nums.at(left);
    }
};
// @lc code=end

