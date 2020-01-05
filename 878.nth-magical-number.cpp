/*
 * @lc app=leetcode id=878 lang=cpp
 *
 * [878] Nth Magical Number
 */

// @lc code=start
class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        long lcm = A * B / gcd(A, B);
        long left = 2, right = 1e14, M = 1e9 + 7;
        while (left < right) {
            long mid = (left + right) >> 1;
            if (mid / A + mid / B - mid / lcm < N) left = mid + 1;
            else right = mid;
        }
        return right % M;
    }

    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
};
// @lc code=end

