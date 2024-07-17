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
    int helper(int d, TreeNode* root){
        if(root!=nullptr){
            return max(helper(d+1, root->left), helper(d+1, root->right));
        } else {
            return d;
        }
    }
    int maxDepth(TreeNode* root) {
        return helper(0, root);
    }
};