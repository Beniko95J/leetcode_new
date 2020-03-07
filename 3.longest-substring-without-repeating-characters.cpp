/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hashmap;
        int left = 0, right = 0;
        int n = s.size();
        int res = 0;
        for (; right < n; right++) {
            if (hashmap.count(s[right]) && hashmap[s[right]] >= left) {
                left = hashmap[s[right]] + 1;
            }
            hashmap[s[right]] = right;
            res = max(res, right - left + 1);
        }

        return res;
    }
};
// @lc code=end

