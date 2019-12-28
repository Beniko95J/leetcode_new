/*
 * @lc app=leetcode id=868 lang=cpp
 *
 * [868] Binary Gap
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    int binaryGap(int N) {
        int last = -1;
        int res = 0;
        for (int i = 0; i < 32; i++) {
            if ((N >> i & 1) != 0) {
                if (last == -1) {
                    last = i;
                    continue;
                } else {
                    res = max(res, i - last);
                    last = i;
                }
            }
        }

        return res;
    }
};
// @lc code=end

