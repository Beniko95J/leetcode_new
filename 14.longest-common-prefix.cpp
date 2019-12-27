/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        else if (strs.size() == 1)
            return strs.at(0);
        else {
            string res = strs.at(0);
            for (size_t i = 1; i < strs.size(); i++)
            {
                while (res != "") {
                    if (strs.at(i).find(res) != 0)
                        res.pop_back();
                    else
                        break;
                }

                if (res == "")
                    break;
            }

            return res;
        }
    }
};

