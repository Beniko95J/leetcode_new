/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // if (nums.size() == 0) return 0;

        // int dp[nums.size()];
        // dp[0] = 1;

        // int res = 1;
        // for (size_t i = 1; i < nums.size(); i++) {
        //     dp[i] = 1;
        //     for (size_t j = 0; j < i; j++) {
        //         if (nums.at(j) < nums.at(i)) {
        //             dp[i] = max(dp[i], dp[j] + 1);
        //         }
        //     }
        //     res = max(res, dp[i]);
        // }

        // return res;

        if (nums.empty()) return 0;
        vector<int> ends{nums[0]};
        for (auto a : nums) {
            if (a < ends[0]) ends[0] = a;
            else if (a > ends.back()) ends.push_back(a);
            else {
                int left = 0, right = ends.size();
                while (left < right) {
                    int mid = left + (right - left) / 2;
                    if (ends[mid] < a) left = mid + 1;
                    else right = mid;
                }
                ends[right] = a;
            }
        }
        return ends.size();
    }
};
// @lc code=end

