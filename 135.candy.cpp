/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start

#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        // vector<int> n(ratings.size(), 1);

        // for (size_t i = 0; i < ratings.size() - 1; i++) {
        //     if (ratings.at(i + 1) > ratings.at(i))
        //         n.at(i + 1) = n.at(i) + 1;
        // }

        // for (size_t i = ratings.size() - 1; i > 0; i--) {
        //     if (ratings.at(i - 1) > ratings.at(i))
        //         n.at(i - 1) = max(n.at(i -1), n.at(i) + 1);
        // }

        // return accumulate(n.begin(), n.end(), 0);

        if (ratings.size() == 0) {
            return 0;
        }

        int res = 1, pre = 1, cnt = 0;
        for (size_t i = 1; i < ratings.size(); i++) {
            if (ratings.at(i) >= ratings.at(i - 1)) {
                if (cnt > 0) {
                    res += cnt * (cnt + 1) / 2;
                    if (cnt >= pre) res += cnt - pre + 1;
                    cnt = 0;
                    pre = 1;
                }
                pre = (ratings.at(i) == ratings.at(i - 1)) ? 1 : pre + 1;
                res += pre;
            } else {
                cnt++;
            }
        }
        if (cnt > 0) {
            res += cnt * (cnt + 1) / 2;
            if (cnt >= pre) res += cnt - pre + 1;
        }

        return res;
    }
};
// @lc code=end

