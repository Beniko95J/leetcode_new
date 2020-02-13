/*
 * @lc app=leetcode id=1090 lang=cpp
 *
 * [1090] Largest Values From Labels
 */

// @lc code=start

#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        multimap<int, int> value_label;
        unordered_map<int, int> label_num;
        int res = 0;
        for (int i = 0; i < values.size(); i++) {
            value_label.insert({values[i], labels[i]});
        }
        for (auto iter = value_label.rbegin(); iter != value_label.rend() && num_wanted > 0; iter++) {
            if (++label_num[iter->second] <= use_limit) {
                res += iter->first;
                num_wanted--;
            }
        }

        return res;
    }
};
// @lc code=end

