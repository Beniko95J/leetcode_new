/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> u;

        for (auto iter = nums.begin(); iter != nums.end(); iter++)
        {
            if (u.count(*iter) == 1)
            {
                int second_idx = distance(nums.begin(), iter);
                auto first_iter = find(nums.begin(), nums.end(), u.at(*iter));
                int first_idx = distance(nums.begin(), first_iter);

                return vector<int>{first_idx, second_idx};
            }
            else
            {
                u.insert({target - *iter, *iter});
            }
        }

        return vector<int>{-1, -1};
    }
};

