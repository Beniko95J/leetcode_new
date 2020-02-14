/*
 * @lc app=leetcode id=850 lang=cpp
 *
 * [850] Rectangle Area II
 */

// @lc code=start

#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        // int res = 0;
        // set<int> sx, sy;
        // for (auto v : rectangles) sx.insert(v[0]), sy.insert(v[1]), sx.insert(v[2]), sy.insert(v[3]);
        // vector<int> x(begin(sx), end(sx)), y(begin(sy), end(sy));
        // vector<vector<int>> m(x.size(), vector<int>(y.size(), 0));

        // for (auto v : rectangles) {
        //     for (auto i = lower_bound(begin(x), end(x), v[0]); *i != v[2]; ++i)
        //     for (auto j = lower_bound(begin(y), end(y), v[1]); *j != v[3]; ++j)
        //         if (m[i - begin(x)][j - begin(y)]++ == 0) 
        //         res = (res + ((long long)*next(i) - *i) * (*next(j) - *j)) % 1000000007;
        // }
        // return res;

        long res = 0, pre_x = 0, height = 0, start = 0, cnt = 0, M = 1e9 + 7;
        map<int, vector<pair<int, int>>> groupMap;
        map<int, int> cntMap;
        for (auto &a : rectangles) {
            groupMap[a[0]].push_back({a[1], 1});
            groupMap[a[0]].push_back({a[3], -1});
            groupMap[a[2]].push_back({a[1], -1});
            groupMap[a[2]].push_back({a[3], 1});
        }
        for (auto &group : groupMap) {
            res = (res + (group.first - pre_x) * height) % M;
            for (auto &a : group.second) {
                cntMap[a.first] += a.second;
            }
            height = 0, start = 0, cnt = 0;
            for (auto &a : cntMap) {
                if (cnt == 0) start = a.first;
                cnt += a.second;
                if (cnt == 0) height += a.first - start;
            }
            pre_x = group.first;
        }
        return res;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<vector<int>> input;
    input.push_back({0, 0, 2, 2});
    input.push_back({1, 0, 2, 3});
    input.push_back({1, 0, 3, 1});
    int output = s.rectangleArea(input);

    return 0;
}
// @lc code=end

