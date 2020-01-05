/*
 * @lc app=leetcode id=877 lang=cpp
 *
 * [877] Stone Game
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return helper(piles, 0, 0, 0, (int)piles.size() - 1, 0);     
    }
    bool helper(vector<int>& piles, int cur0, int cur1, int left, int right, int player) {
        if (left > right) return cur0 > cur1;
        if (player == 0) {
            return helper(piles, cur0 + piles[left], cur1, left + 1, right, 1) || helper(piles, cur0 + piles[right], cur1, left + 1, right, 1);
        } else {
            return helper(piles, cur0, cur1 + piles[left], left, right - 1, 0) || helper(piles, cur0, cur1 + piles[right], left, right - 1, 0);
        }
    }
};
// @lc code=end

