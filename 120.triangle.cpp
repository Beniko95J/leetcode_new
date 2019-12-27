/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0)
            return 0;
        
        vector<vector<int>> res(triangle);
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j < triangle.at(i).size(); j++) {
                res.at(i).at(j) += min(res.at(i+1).at(j), res.at(i+1).at(j+1));
            }
        }

        return res.at(0).at(0);
    }
};
// @lc code=end

