/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        TreeNode* q = root;
        while(q || !st.empty()){
            while(q){
                st.push(q);
                q = q->left;
            }
            TreeNode* top = st.top();
            st.pop();
            res.emplace_back(top->val);
            q = top->right;
            
        }
        return res;
    }
};
// @lc code=end

