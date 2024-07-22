/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode* root, int& k, int& val) {
        if (k == 0) {
            return true;
        }
        if (root == NULL)
            return false;
        if (helper(root->left, k, val))
            return true;
        k--;
        val = root->val;
        if (helper(root->right, k, val))
            return true;
        return false;
    }

    int kthSmallest(TreeNode* root, int k) {
        int val = -1;
        helper(root, k, val);
        return val;
    }
};