/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

#include <string>
#include <stack>
#include <iostream>
#include <typeinfo>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (size_t idx = 0; idx < s.size(); idx++) {
            char c = s.at(idx);
            
            if (c == '(' || c == '{' || c== '[') {
                st.push(c);
            }
            else {
                if (c == ')') {
                    if (st.empty() || st.top() != '(')
                        return false;
                    else
                        st.pop();
                }
                else if (c == '}') {
                    if (st.empty() || st.top() != '{')
                        return false;
                    else
                        st.pop();
                }
                else {
                    if (st.empty() || st.top() != '[')
                        return false;
                    else
                        st.pop();
                }
            }
        }

        if (!st.empty())
            return false;
        else
            return true;
    }
};

