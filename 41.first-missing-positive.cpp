/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int res = 1;
        unordered_set<int> us;

        for (size_t i = 0; i < nums.size(); i++) {
            if (nums.at(i) < 1)
                continue;
            else {
                us.insert(nums.at(i));
            }
        }

        while (us.count(res) == 1) {
            res++;
        }

        return res;
    }
};

