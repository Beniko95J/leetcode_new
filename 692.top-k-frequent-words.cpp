/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res(k);
        unordered_map<string, int> um;

        for (const auto& word: words) {
            if (um.count(word) == 1)
                um.at(word) = um.at(word) + 1;
            else
                um.insert(pair<string, int>{word, 1});
        }

        auto cmp = [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cmp);
        for (auto p: um) {
            pq.push(p);
            if (pq.size() > k) pq.pop();
        }

        for (int i = res.size() - 1; i >= 0; i--) {
            res.at(i) = pq.top().first;
            pq.pop();
        }

        return res;
    }
};

