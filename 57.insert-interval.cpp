/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left_pos = 0;
        for (size_t i = 0; i < intervals.size(); i++) {
            if (newInterval.at(0) > intervals.at(i).at(1))
                left_pos++;
            else
                break;
        }

        int right_pos = 0;
        for (size_t i = 0; i < intervals.size(); i++) {
            if (newInterval.at(1) >= intervals.at(i).at(0))
                right_pos++;
            else
                break;
        }

        if (left_pos == right_pos) {
            intervals.insert(intervals.begin() + left_pos, newInterval);
        }
        else {
            int new_left = min(intervals.at(left_pos).at(0), newInterval.at(0));
            int new_right = max(intervals.at(right_pos - 1).at(1), newInterval.at(1));
            intervals.erase(intervals.begin() + left_pos, intervals.begin() + right_pos);
            intervals.insert(intervals.begin() + left_pos, vector<int>{new_left, new_right});
        }

        return intervals;
    }
};

