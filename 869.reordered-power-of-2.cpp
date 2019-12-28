/*
 * @lc app=leetcode id=869 lang=cpp
 *
 * [869] Reordered Power of 2
 */

// @lc code=start

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        string str = to_string(N);
        sort(str.begin(), str.end());
        for (int i = 0; i < 31; i++) {
            string t = to_string(1 << i);
            sort(t.begin(), t.end());
            if (str == t) return true;
        }

        return false;
    }
};
// @lc code=end

