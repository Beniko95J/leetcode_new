/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start

#include <string>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;

        for (size_t i = 0; i < s.size(); i++) {
            int left = i;
            int right = i;
            while (left >= 0 && right < s.size() && s.at(left) == s.at(right)) {
                res++;
                left--;
                right++;
            }

            left = i;
            right = i + 1;
            while (left >= 0 && right < s.size() && s.at(left) == s.at(right)) {
                res++;
                left--;
                right++;
            }
        }

        return res;

        // if (s.size() == 0) {
        //     return 0;
        // }

        // int res = 0;
        // bool dp[s.size()][s.size()];
        // for (int i = s.size() - 1; i >= 0; i--) {
        //     for (int j = i; j < s.size(); j++) {
        //         dp[i][j] = (s[i] == s[j]) && (j - i <= 2 || dp[i + 1][j - 1]);
        //         if (dp[i][j]) {
        //             res++;
        //         }
        //     }
        // }

        // return res;
    }
};
// @lc code=end

