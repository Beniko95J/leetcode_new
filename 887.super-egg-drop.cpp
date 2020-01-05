/*
 * @lc app=leetcode id=887 lang=cpp
 *
 * [887] Super Egg Drop
 */

// @lc code=start

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

class Solution {
public:
    int superEggDrop(int K, int N) {
        unordered_map<pair<int, int>, int, hash_pair> memo;

        return helper(K, N, memo);
    }

    int helper(int K, int N, unordered_map<pair<int, int>, int, hash_pair>& memo) {
        if (K == 1) {
            return N;
        }

        if (N == 0) return 0;

        if (memo.count({K, N})) return memo[{K, N}];

        int res = __INT_MAX__;
        for (int i = 1; i<= N; i++) {
            res = min(res, 1 + max(helper(K-1, i-1, memo), helper(K, N-i, memo)));
        }
        memo.insert({{K, N}, res});
        return res;
    }
};

// int main(int argc, char** argv) {
//     Solution s;
//     int res = s.superEggDrop(2, 6);
//     cout << res << endl;

//     return 0;
// }
// @lc code=end

