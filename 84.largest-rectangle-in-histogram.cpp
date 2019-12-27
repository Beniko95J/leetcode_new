/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start

#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // int res = 0;

        // if (heights.empty()) return res;

        // largestRectangleAreaHelper(heights, 0, heights.size() - 1, res);

        // return res;
        
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

    // void largestRectangleAreaHelper(const vector<int>& heights,
    //                                 int begin,
    //                                 int end,
    //                                 int& largest)
    // {   
    //     if (begin == end) {
    //         int cur_largest = heights.at(begin);
    //         if (cur_largest > largest) {
    //             largest = cur_largest;
    //         }
    //         return;
    //     }

    //     auto cur_min = min_element(heights.begin() + begin, heights.begin() + end + 1);
    //     int cur_length = end - begin + 1;
    //     int cur_largest = (*cur_min) * cur_length;
    //     if (cur_largest > largest) {
    //             largest = cur_largest;
    //     }
    //     int cur_min_idx = distance(heights.begin(), cur_min);

    //     if (cur_min_idx != begin) largestRectangleAreaHelper(heights, begin, cur_min_idx - 1, largest);
    //     if (cur_min_idx != end) largestRectangleAreaHelper(heights, cur_min_idx + 1, end, largest);
    // }
};

// int main(int argc, char** argv)
// {
//     Solution s;
//     vector<int> heights;
//     heights.push_back(1);

//     s.largestRectangleArea(heights);

//     return 0;
// }
// @lc code=end

