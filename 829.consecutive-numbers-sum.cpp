/*
 * @lc app=leetcode id=829 lang=cpp
 *
 * [829] Consecutive Numbers Sum
 */

// @lc code=start
class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int res = 0;

        for (int n = 1; n < N + 1; n++) {
            if (2 * N - n * (n - 1) <= 0) break;
            int x = (2 * N - n * (n - 1)) / (2 * n);
            if ((2 * N - n * (n - 1) - 2 * n * x) == 0)
            {
                res++;
            }
        }

        return res;
    }
};
// @lc code=end

