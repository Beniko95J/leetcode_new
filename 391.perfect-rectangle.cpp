/*
 * @lc app=leetcode id=391 lang=cpp
 *
 * [391] Perfect Rectangle
 */

// @lc code=start

#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_set<string> u_set;
        int min_x = INT32_MAX, min_y = INT32_MAX, max_x = INT32_MIN, max_y = INT32_MIN, area = 0;
        for (const auto& rect : rectangles) {
            min_x = min(min_x, rect[0]);
            min_y = min(min_y, rect[1]);
            max_x = max(max_x, rect[2]);
            max_y = max(max_y, rect[3]);
            area += (rect[2] - rect[0]) * (rect[3] - rect[1]);
            string s1 = to_string(rect[0]) + "_" + to_string(rect[1]);
            string s2 = to_string(rect[0]) + "_" + to_string(rect[3]); // top-left
            string s3 = to_string(rect[2]) + "_" + to_string(rect[3]); // top-right
            string s4 = to_string(rect[2]) + "_" + to_string(rect[1]); // bottom-right
            
            if (u_set.count(s1)) u_set.erase(s1);
            else u_set.insert(s1);
            if (u_set.count(s2)) u_set.erase(s2);
            else u_set.insert(s2);
            if (u_set.count(s3)) u_set.erase(s3);
            else u_set.insert(s3);
            if (u_set.count(s4)) u_set.erase(s4);
            else u_set.insert(s4);
        }

        string t1 = to_string(min_x) + "_" + to_string(min_y);
        string t2 = to_string(min_x) + "_" + to_string(max_y);
        string t3 = to_string(max_x) + "_" + to_string(max_y);
        string t4 = to_string(max_x) + "_" + to_string(min_y);
        if (!u_set.count(t1) || !u_set.count(t2) || !u_set.count(t3) || !u_set.count(t4) || u_set.size() != 4) return false;
        return area == (max_x - min_x) * (max_y - min_y);
    }
};
// @lc code=end

