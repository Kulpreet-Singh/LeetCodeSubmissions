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
    bool validate(TreeNode* root, long leftLimit, long rightLimit){
        if(root == nullptr) return true;
        if(root->val>=rightLimit || root->val<=leftLimit){
            return false;
        }
        return validate(root->left, leftLimit, root->val) && validate(root->right, root->val, rightLimit);
    }
    bool isValidBST(TreeNode* root) {
        return validate(root, (long)INT_MIN-1, (long)INT_MAX+1);
    }
};