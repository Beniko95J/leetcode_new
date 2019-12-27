/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
        {
            return false;
        }

        string s = to_string(x);
        string s1(s.rbegin(), s.rend());

        if (!s.compare(s1))
            return true;
        else
            return false;
    }
};

