/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start

#include <vector>
#include <cstddef>
#include <numeric>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, __INT_MAX__);
        dp.at(0) = 0;

        for (size_t i = 0; i <= n; i++) {
            for (int j = 1; i + j * j <= n; j++) {
                dp.at(i + j * j) = min(dp.at(i + j * j), dp[i] + 1);
            }
        }

        return dp.back();
    }
};
// @lc code=end

