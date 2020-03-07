/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int res = 0;

        int i = 0, j = 0;
        int n = chars.size();
        for (; i < n; i = j) {
            while (j < n && chars[j] == chars[i]) j++;
            chars[res++] = chars[i];
            if (j - i == 1) continue;
            for (char c : to_string(j - i)) chars[res++] = c;
        }

        return res;
    }
};
// @lc code=end

