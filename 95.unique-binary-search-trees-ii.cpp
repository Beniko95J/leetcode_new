/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <cstddef>
#include <vector>

using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            vector<TreeNode*> res;
            return res;
        }

        return helper(1, n);
    }

    vector<TreeNode*> helper(int start, int end) {
        vector<TreeNode*> res;

        if (start > end) {
            res.push_back(NULL);
            return res;
        }

        if (start == end) {
            res.push_back(new TreeNode(start));
            return res;
        }

        vector<TreeNode*> left, right;
        for (int i = start; i <= end; i++) {
            left = helper(start, i - 1);
            right = helper(i + 1, end);

            for (auto lnode : left) {
                for (auto rnode : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = lnode;
                    root->right = rnode;
                    res.push_back(root);
                }
            }
        }

        return res;
    }
};
// @lc code=end

