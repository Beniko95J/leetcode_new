/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 */

// @lc code=start

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;

        string res;
        int i = 0;
        vector<string> container(numRows);
        while (i < s.size()) {
            for (int pos = 0; pos < numRows && i < s.size(); pos++) {
                container[pos] += s[i++];
            }
            for (int pos = numRows - 2; pos > 0 && i < s.size(); pos--) {
                container[pos] += s[i++];
            }
        }

        for (auto s : container) res += s;

        return res;
    }
};
// @lc code=end

