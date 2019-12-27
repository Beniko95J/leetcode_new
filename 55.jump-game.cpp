/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;

        for (size_t i = 0; i < nums.size(); i++) {
            if (i > reach)
                break;
            reach = max<int>(i + nums.at(i), reach);
            if (reach >= nums.size() - 1)
                break;
        }

        return reach >= nums.size() - 1;
    }
};

