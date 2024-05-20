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
    TreeNode* helper(vector<int>& preorder, int i, int j){
        if(i>=j){
            return nullptr;
        }
        TreeNode* root = new TreeNode();
        root->val = preorder[i];
        int k =i+1;
        while(k<j && preorder[k]<root->val){
            k++;
        }
        root->left = helper(preorder, i+1, k);
        root->right = helper(preorder, k, j);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, 0, preorder.size());
    }
};