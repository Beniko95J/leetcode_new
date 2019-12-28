/*
 * @lc app=leetcode id=870 lang=cpp
 *
 * [870] Advantage Shuffle
 */

// @lc code=start

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        sort(A.begin(), A.end());
        int left = 0; int right = A.size() - 1;
        vector<int> res(A.size());
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < B.size(); i++) pq.push({B[i], i});

        while (!pq.empty()) {
            int val = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            if (A.at(right) > val) res.at(idx) = A.at(right--);
            else res.at(idx) = A.at(left++);
        }

        return res;
    }
};
// @lc code=end

