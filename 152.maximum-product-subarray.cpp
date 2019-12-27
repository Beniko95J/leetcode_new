/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int res = nums.at(0);
        int f[nums.size()], g[nums.size()];
        f[0] = nums.at(0);
        g[0] = nums.at(0);

        for (size_t i = 1; i < nums.size(); i++) {
            f[i] = max({f[i - 1] * nums.at(i), g[i - 1] * nums.at(i), nums.at(i)});
            g[i] = min({f[i - 1] * nums.at(i), g[i - 1] * nums.at(i), nums.at(i)});
            res = max(res, f[i]);
        }

        return res;
    }
};
// @lc code=end

