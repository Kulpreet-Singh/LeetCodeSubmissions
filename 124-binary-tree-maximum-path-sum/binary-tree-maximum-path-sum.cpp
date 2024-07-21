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
    int helper(TreeNode* root, int& maxi){
        if(root==nullptr) return 0;
        int leftpath = helper(root->left, maxi);
        if(leftpath<0) leftpath = 0;
        int rightpath = helper(root->right, maxi);
        if(rightpath<0) rightpath = 0;
        maxi = max(maxi, root->val+leftpath+rightpath);
        return root->val + max(leftpath, rightpath);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        helper(root, maxi);
        return maxi;
    }
};