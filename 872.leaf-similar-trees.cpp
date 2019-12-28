/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
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
#include <string>

using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string leaf_1;
        string leaf_2;

        helper(root1, leaf_1);
        helper(root2, leaf_2);

        return leaf_1 == leaf_2;
    }

    void helper(TreeNode* root, string& leaf) {
        if (root->left == NULL && root->right == NULL) {
            leaf += to_string(root->val);
            return;
        }

        if (root->left != NULL) helper(root->left, leaf);
        if (root->right != NULL) helper(root->right, leaf);
    }
};
// @lc code=end

