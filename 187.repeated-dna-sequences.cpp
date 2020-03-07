/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 */

// @lc code=start

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> container;
        int n = s.size();
        if (n < 10) return vector<string>();

        for (int i = 0; i <= n - 10; i++) {
            string sub_string = s.substr(i, 10);
            container[sub_string]++;
        }

        vector<string> res;
        for (auto record : container) {
            if (record.second > 1) {
                res.push_back(record.first);
            }
        }

        return res;
    }
};
// @lc code=end

