/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start

#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        // int res = __INT_MAX__;
        // int n = piles.size();
        // vector<double> d_piles(piles.begin(), piles.end());
        // vector<int> times(n, 1);
        // for (int i = n; i <= H; i++) {
        //     int max_idx = max_element(d_piles.begin(), d_piles.end()) - d_piles.begin();
        //     res = min(res, int(ceil(d_piles[max_idx])));
        //     times[max_idx] += 1;
        //     d_piles[max_idx] = double(piles[max_idx]) / double(times[max_idx]);
        // }

        // return res;

        int left = 1, right = 1e9;
        while (left < right) {
            int mid = (left + right) / 2, cnt = 0;
            for (auto pile : piles) cnt += (pile + mid -1) / mid;
            if (cnt > H) left = mid + 1;
            else right = mid;
        }

        return right;
    }
};
// @lc code=end

