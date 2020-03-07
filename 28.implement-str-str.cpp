/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        if (haystack.size() < needle.size()) return -1;

        vector<int> next = getNext(needle);

        int i = 0;
        int j = 0;
        int m = haystack.size();
        int n = needle.size();
        while (i < m && j < n) {
            if (j == -1 || haystack[i] == needle[j]) {
                i++;
                j++;
            }
            else j = next[j];
        }
        if (j == needle.size()) return i - j;
        else return -1;
    }

    vector<int> getNext(string str) {
        int n = str.size();

        // if (n == 1) return {-1};

        vector<int> res(n);
        res[0] = -1;

        int j = -1;
        for (int i = 1; i < n;) {
            if (j == -1 || str[i - 1] == str[j]) {
                j++;
                res[i] = j;
                i++;
            } else {
                j = res[j];
            }
        }

        return res;
    }
};
// @lc code=end

