/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 */

// @lc code=start

#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> height;
        vector<vector<int>> res;
        multiset<int> heap;
        for (const auto &iter : buildings) {
            height.push_back({iter[0], -iter[2]});
            height.push_back({iter[1], iter[2]});
        }
        sort(height.begin(), height.end());

        heap.insert(0);
        int pre = 0, cur = 0;
        for (const auto& iter : height) {
            if (iter.second < 0) {
                heap.insert(-iter.second);
            }
            else {
                heap.erase(heap.find(iter.second));
            }
            cur = *heap.rbegin();
            if (cur != pre) {
                res.push_back({iter.first, cur});
                pre = cur;
            }
        }

        return res;
    }
};
// @lc code=end

