/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> all_comb;
        vector<int> cur_comb;
        helper(candidates, target, 0, cur_comb, all_comb);
        return all_comb;
    }

    void helper(vector<int>& candidates, int target, int start, vector<int>& cur_comb, vector<vector<int>>& all_comb) {
        if (target == 0) {
            all_comb.push_back(cur_comb);
            return;
        }
        else if (target < 0) return;
        else {
            for (size_t i = start; i < candidates.size(); i++) {
                cur_comb.push_back(candidates[i]);
                helper(candidates, target - candidates[i], i, cur_comb, all_comb);
                cur_comb.pop_back();
            }
        }
    }
};
// @lc code=end

