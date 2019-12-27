/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix.at(0).size() == 0) return 0;
        int dp[matrix.size()][matrix.at(0).size()];

        int res = 0;
        for (size_t i = 0; i < matrix.size(); i++) {
            for (size_t j = 0; j < matrix.at(0).size(); j++) {
                if (i == 0 || j == 0) dp[i][j] = matrix.at(i).at(j) - '0';
                else {
                    dp[i][j] = matrix.at(i).at(j) == '1' ? min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]}) + 1 : 0;
                }
                res = max(res, dp[i][j]);
            }
        }

        return res * res;
    }
};
// @lc code=end

