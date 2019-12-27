/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        size_t s = height.size();
        vector<int> from_left(s);
        vector<int> from_right(s);
        int max_from_left = 0;
        int max_from_right = 0;

        for (size_t i = 0; i < s; i++) {
            max_from_left = max(height.at(i), max_from_left);
            max_from_right = max(height.at(s - i -1), max_from_right);
            from_left.at(i) = max_from_left;
            from_right.at(s - i -1) = max_from_right;
        }

        vector<int> container(s);
        for (size_t i = 0; i < s; i++) {
            container.at(i) = min(from_left.at(i), from_right.at(i));
        }

        int sum_of_container = accumulate(container.begin(), container.end(), 0);
        int sum_of_height = accumulate(height.begin(), height.end(), 0);

        return sum_of_container - sum_of_height;
    }
};

