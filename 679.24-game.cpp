/*
 * @lc app=leetcode id=679 lang=cpp
 *
 * [679] 24 Game
 */

// @lc code=start

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        bool res = false;
        double eps = 0.001;
        vector<double> arr(nums.begin(), nums.end());
        helper(arr, eps, res);
        return res;
    }

    void helper(vector<double>& nums, double eps, bool& res) {
        if (res) return;
        if (nums.size() == 1) {
            if (abs(nums[0] - 24) < eps) res = true;

            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                double p = nums[i];
                double q = nums[j];
                vector<double> t{p + q, p - q, q - p, p * q};
                if (abs(p) > eps) t.push_back(q / p);
                if (abs(q) > eps) t.push_back(p / q);
                nums.erase(nums.begin() + i);
                nums.erase(nums.begin() + j);
                for (double d : t) {
                    nums.push_back(d);
                    helper(nums, eps, res);
                    nums.pop_back();
                }
                nums.insert(nums.begin() + j, q);
                nums.insert(nums.begin() + i, p);
            }
        }
    }
};
// @lc code=end

