/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start

#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res = 0;
        vector<int> heights;

        for (size_t i = 0; i < matrix.size(); i++)
        {
            heights.resize(matrix.at(i).size(), 0);
            for (size_t j = 0; j < matrix.at(i).size(); j++)
            {
                heights[j] = matrix[i][j] == '0' ? 0 : (1 + heights[j]);
            }
            int tmp_res = largestRectangleArea(heights);
            res = max(res, tmp_res);
        }

        return res;
    }

    int largestRectangleArea(vector<int>& heights) {
        int res = 0;

        if (heights.empty()) return res;

        stack<int> st;
        int h, w;
        heights.push_back(0);

        for (size_t i = 0; i < heights.size(); i++)
        {
            if (st.empty() || heights.at(i) >= heights.at(st.top()))
            {
                st.push(i);
            }
            else
            {
                while (!st.empty() && heights.at(i) < heights.at(st.top()))
                {
                    h = heights.at(st.top());
                    while (!st.empty() && heights.at(st.top()) == h) st.pop();
                    w = st.empty() ? i : i - st.top() - 1;
                    res = max(res, h * w);
                }
                st.push(i);
            }
        }

        return res;
    }
};
// @lc code=end

