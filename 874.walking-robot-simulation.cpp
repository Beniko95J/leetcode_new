/*
 * @lc app=leetcode id=874 lang=cpp
 *
 * [874] Walking Robot Simulation
 */

// @lc code=start

#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> obs;
        for (auto i : obstacles) {
            obs.emplace(to_string(i[0]) + "-" + to_string(i[1]));
        }
        int res = 0, x = 0, y = 0, idx = 0;
        vector<int> dirX{0, 1, 0, -1}, dirY{1, 0, -1, 0};

        for (auto cmd : commands) {
            if (cmd == -2) idx = (idx - 1 + 4) % 4;
            else if (cmd == -1) idx = (++idx) % 4;
            else {
                while (cmd-- > 0 && !obs.count(to_string(x+dirX[idx]) + "-" + to_string(y+dirY[idx]))) {
                    x += dirX[idx];
                    y += dirY[idx];
                }
            }

            res = max(res, x*x + y*y);
        }

        return res;
    }
};
// @lc code=end

