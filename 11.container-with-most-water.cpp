/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        unsigned int i = 0;
        unsigned int j = height.size() - 1;
        int res = min(height.at(i), height.at(j)) * (j - i);

        while (i < j)
        {
            if (height.at(i) < height.at(j))
                i++;
            else
                j--;
            
            int tmp_res = min(height.at(i), height.at(j)) * (j - i);
            if (tmp_res > res)
                res = tmp_res;
        }

        return res;
    }
};

