/*
 * @lc app=leetcode id=849 lang=cpp
 *
 * [849] Maximize Distance to Closest Person
 */

// @lc code=start

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> sitted;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 1) {
                sitted.push_back(i);
            }
        }

        int res = 1;
        for (int i = 0; i < sitted.size() - 1; i++) {
                res = max(res, (sitted[i+1] - sitted[i]) / 2);
        }

        res = max(res, sitted[0]);
        res = max<int>(res, seats.size() - 1 - sitted[sitted.size() - 1]);

        return res;
    }
};

// int main(int argc, char** argv) {
//     Solution s;
//     vector<int> seats{1, 0, 0, 0};

//     int res = s.maxDistToClosest(seats);
//     cout << res << endl;
// }
// @lc code=end

