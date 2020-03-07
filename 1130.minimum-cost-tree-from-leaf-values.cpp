/*
 * @lc app=leetcode id=1130 lang=cpp
 *
 * [1130] Minimum Cost Tree From Leaf Values
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> maxs(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            maxs[i][i] = arr[i];
        }
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < j; i++) {
                maxs[i][j] = max(maxs[i][j-1], arr[j]);
            }
        }

        vector<vector<int>> dp(n, vector<int>(n, __INT_MAX__));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 0;
        }
        for (int j = 1; j < n; j++) {
            for (int i = j - 1; i >= 0; i--) {
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + maxs[i][k] * maxs[k+1][j]);
                }
            }
        }

        return dp[0][n-1];
    }
};

// int main(int argc, char** argv) {
//     Solution s;
//     vector<int> input{6, 2, 4};
//     s.mctFromLeafValues(input);

//     return 0;
// }
// @lc code=end

