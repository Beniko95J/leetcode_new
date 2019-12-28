/*
 * @lc app=leetcode id=871 lang=cpp
 *
 * [871] Minimum Number of Refueling Stops
 */

// @lc code=start

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // int res = -1;
        // vector<long> dp(stations.size() + 1, -1);
        // dp.at(0) = startFuel;

        // for (int i = 0; i < stations.size(); i++) {
        //     for (int j = i; j >= 0; j--) {
        //         if (dp.at(j) >= stations.at(i)[0]) {
        //             dp.at(j + 1) = max(dp.at(j + 1), dp.at(j) + stations.at(i)[1]);
        //         }
        //     }
        // }

        // for (int i = 0; i < dp.size(); i++) {
        //     cout << dp[i] << endl;
        //     if (dp[i] >= target) return i;
        // }

        // return -1;

        int res = 0;
        priority_queue<int> pq;
        pq.push(startFuel);
        int traveled = 0;
        int i = 0;
        while (traveled < target && !pq.empty()) {
            int t = pq.top(); pq.pop();
            traveled += t;
            res++;
            for (int j = i; j < stations.size(); j++) {
                if (stations[j][0] <= traveled) {
                    pq.push(stations[j][1]);
                    i++;
                }
            }
        }

        if (traveled >= target) return res - 1;
        else return -1;
    }
};
// @lc code=end

