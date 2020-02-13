/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();
        vector<int> dp(days, 0);
        int res = 0;

        if (days < 2) return 0;

        for (int i = 1; i < days; i++) {
            for (int j = 0; j < i; j++) {
                if (prices[j] <= prices[i]) {
                    dp[i] = max(dp[i], dp[j] + prices[i] - prices[j]);
                }
                else {
                    continue;
                }
            }

            res = max(res, dp[i]);
        }

        return res;
    }
};
// @lc code=end

