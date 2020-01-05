/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 */

// @lc code=start

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res(2, -1);
        
        unordered_map<int, pair<int, int>> hashmap;

        for (int i = 0; i < numbers.size(); i++) {
            if (hashmap.count(numbers[i])) {
                res[0] = hashmap[numbers[i]].second + 1;
                res[1] = i + 1;
                return res;
            }
            else {
                hashmap.emplace(make_pair(target - numbers[i], make_pair(numbers[i], i)));
            }
        }

        return res;
    }
};
// @lc code=end

