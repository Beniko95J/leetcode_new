/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */

// @lc code=start

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.size() < t.size())
            return 0;
        
        unsigned int mem[t.size() + 1][s.size() + 1];
        for (size_t i = 0; i < s.size() + 1; i++) {
            mem[0][i] = 1;
        }
        for (size_t i = 1; i < t.size() + 1; i++) {
            mem[i][0] = 0;
        }

        for (size_t i = 1; i < t.size() + 1; i++) {
            for (size_t j = 1; j < s.size() + 1; j++) {
                if (s.at(j - 1) == t.at(i - 1)) {
                    mem[i][j] = mem[i][j - 1] + mem[i - 1][j - 1];
                }
                else {
                    mem[i][j] = mem[i][j - 1];
                }
            }
        }

        return mem[t.size()][s.size()];
    }
};
// @lc code=end

