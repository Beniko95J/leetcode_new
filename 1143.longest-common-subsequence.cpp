/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> length(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    length[i][j] = length[i-1][j-1] + 1;
                }
                else {
                    length[i][j] = max(length[i-1][j], length[i][j-1]);
                }
            }
        }

        return length[m][n];
    }
};
// @lc code=end

