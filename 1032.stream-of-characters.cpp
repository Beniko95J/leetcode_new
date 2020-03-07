/*
 * @lc app=leetcode id=1032 lang=cpp
 *
 * [1032] Stream of Characters
 */

// @lc code=start

#include <vector>
#include <string>

using namespace std;

class StreamChecker {
public:
    struct TrieNode {
        TrieNode* next[26];
        bool flag;
        TrieNode() : flag(false), next({NULL}) {}
    };

    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        for (const auto& w : words) {
            auto node = root;
            for (int i = w.size() - 1; i >= 0; i--) {
                int k = w[i] - 'a';
                if (node->next[k] == NULL) {
                    node->next[k] = new TrieNode();
                }
                node = node->next[k];
            }
            node->flag = true;
        }
    }
    
    bool query(char letter) {
        s += letter;
        auto node = root;
        for (int i = s.size() - 1; i >= 0; i--) {
            int k = s[i] - 'a';
            if (node->next[k] == NULL) return false;
            else {
                node = node->next[k];
                if (node->flag == true) return true;
            }
        }
        return false;
    }

private:
    TrieNode* root;
    string s;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
// @lc code=end

