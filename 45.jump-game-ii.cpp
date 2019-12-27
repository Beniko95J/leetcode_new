/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        // size_t s = nums.size();
        
        // vector<int> jump(s);
        // jump.at(s - 1) = 0;

        // for (int i = s - 2; i > -1; i--) {
        //     auto start = jump.begin() + i + 1;
        //     int end_i = min<int>(s - 1, i + nums.at(i));
        //     auto end = jump.begin() + end_i;

        //     auto min = min_element(start, end + 1);
        //     jump.at(i) = *min + 1;
        // }

        // return jump.at(0);

        // size_t s = nums.size();

        // vector<int> jump(s, -1);
        // jump.at(0) = 0;
        // int reach = 0;

        // for (size_t i = 0; i < s; i++) {
        //     reach = max<int>(i + nums.at(i), reach);

        //     if (reach >= s - 1) {
        //         if (i == s - 1)
        //             return jump.at(i);
        //         else
        //             return jump.at(i) + 1;
        //     }

        //     for (size_t j = i + 1; j <= reach; j++) {
        //         if (jump.at(j) == -1)
        //             jump.at(j) = jump.at(i) + 1;
        //     }
        // }

        // return jump.at(s - 1);

        int cur = 0, ret = 0, last = 0;

        for (size_t i = 0; i < nums.size(); i++) {
            if (i > last) {
                last = cur;
                ret++;
            }

            cur = max<int>(cur, i + nums.at(i));
        }

        return ret;
    }
};

