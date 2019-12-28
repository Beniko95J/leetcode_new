/*
 * @lc app=leetcode id=873 lang=cpp
 *
 * [873] Length of Longest Fibonacci Subsequence
 */

// @lc code=start

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        // if (A.size() == 0) return 0;
        
        // int res = 0;
        // int n = A.size();
        // vector<vector<int>> dp(n, vector<int>(n));
        // unordered_map<int, int> m;
        // for (int i = 0; i < n; i++) {
        //     m[A[i]] = i;
        //     for (int j = 0; j < i; j++) {
        //         int k = m.count(A[i] - A[j]) ? m[A[i] - A[j]] : -1;
        //         dp[j][i] = (A[i] - A[j] < A[j] && k >= 0) ? (dp[k][j] + 1) : 2;
        //         res = max(res, dp[j][i]);
        //     }
        // }

        // return (res > 2) ? res : 0;

        int res = 0, n = A.size();
        unordered_set<int> st(A.begin(), A.end());
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a = A[i], b = A[j], cnt = 2;
                while (st.count(a + b)) {
                    b = a + b;
                    a = b - a;
                    ++cnt;
                }
                res = max(res, cnt);
            }
        }
        return (res > 2) ? res : 0;
    }
};
// @lc code=end

