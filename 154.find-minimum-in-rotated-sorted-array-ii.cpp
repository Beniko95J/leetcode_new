/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
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
            if (nums.at(mid) > nums.at(left)) left = mid + 1;
            else if (nums.at(mid) < nums.at(left)) right = mid;
            else left++;
        }

        return nums.at(left);
    }
};
// @lc code=end

