/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 */

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        if (s.size() == 0) {
            return 0;
        }

        int dp[s.size()];
        bool dp_647[s.size()][s.size()];
        dp[0] = 0;

        for (int i = 1; i < s.size(); i++) {
            dp[i] = i;
            for (int j = 0; j <= i; j++) {
                dp_647[j][i] = (s[i] == s[j]) && (i - j < 2 || dp_647[j + 1][i - 1]);
                if (dp_647[j][i]) {
                    dp[i] = (j == 0) ? 0 : min(dp[i], dp[j - 1] + 1);
                }
            }
        }

        return dp[s.size() - 1];
    }
};
// @lc code=end

