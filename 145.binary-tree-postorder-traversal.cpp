/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
#include <stack>

using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // ### recursive ###
        // vector<int> res;
        // helper(root, res);
        // return res;

        // ### iterative ###
        if (root == NULL) return vector<int>();
        vector<int> res;
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* head = root;

        while (!st.empty()) {
            TreeNode* t = st.top();
            if ((!t->left && !t->right) || t->left == head || t->right == head) {
                res.push_back(t->val);
                st.pop();
                head = t;
            }
            else {
                if (t->right != NULL) st.push(t->right);
                if (t->left != NULL) st.push(t->left);
            }
        }

        return res;
    }

    void helper(TreeNode* root, vector<int>& res) {
        if (root == NULL) {
            return;
        }
        
        if (root->left == NULL && root->right == NULL) {
            res.push_back(root->val);
            return;
        }

        if (root->left != NULL) helper(root->left, res);
        if (root->right != NULL) helper(root->right, res);
        res.push_back(root->val);
    }
};
// @lc code=end

