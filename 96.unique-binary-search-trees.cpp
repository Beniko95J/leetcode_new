/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        vector<int> mem(n + 1, -1);
        mem.at(0) = 1;
        mem.at(1) = 1;

        return helper(n, mem);
    }

    int helper(int n, vector<int>& mem) {
        if (mem.at(n) != -1)
            return mem.at(n);
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += helper(i, mem) * helper(n - 1 - i, mem);
        }
        mem.at(n) = res;
        return res;
    }
};

// int main(int argc, char** argv) {
//     Solution s;
//     s.numTrees(2);

//     return 0;
// }
// @lc code=end

