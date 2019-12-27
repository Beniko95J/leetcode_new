/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        vector<int> mutable_num(nums);
        std::sort(mutable_num.begin(), mutable_num.end(), [](int i, int j){return i < j;});

        int result = mutable_num.at(0) + mutable_num.at(1) + mutable_num.at(2);
        for (size_t i = 0; i < mutable_num.size() - 2; i++) {
            size_t j = i + 1;
            size_t k = mutable_num.size() - 1;
            int difference = mutable_num.at(i) + mutable_num.at(j) + mutable_num.at(k) - target;
            int res = mutable_num.at(i) + mutable_num.at(j) + mutable_num.at(k);
            
            while (j < k) {
                if (difference > 0)
                    k--;
                else if (difference < 0)
                    j++;
                else
                    return target;
                
                if (!(j < k))
                    break;
                
                int new_difference = mutable_num.at(i) + mutable_num.at(j) + mutable_num.at(k) - target; 
                if (std::abs(new_difference) < std::abs(difference))
                    res = mutable_num.at(i) + mutable_num.at(j) + mutable_num.at(k);
                difference = new_difference;
            }

            result = abs(res - target) < abs(result - target) ? res : result;
        }

        return result;
    }
};

