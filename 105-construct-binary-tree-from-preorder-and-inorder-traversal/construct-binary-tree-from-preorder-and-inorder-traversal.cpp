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
TreeNode* builder(vector<int>& inorder, int is, int ie,
                      vector<int>& preorder, int ps, int pe,
                      map<int, int>& hashMap) {
        if (is > ie || ps > pe) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[ps]);
        int inRoot = hashMap[preorder[ps]];
        int numLeft = inRoot - is;

        root->left = builder(inorder, is, inRoot - 1, preorder, ps+1,
                             ps + numLeft, hashMap);

        root->right = builder(inorder, inRoot + 1, ie, preorder, ps + numLeft+1,
                              pe, hashMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.size() != preorder.size()) {
            return nullptr;
        }
        map<int, int> hashMap;
        for (int i = 0; i < inorder.size(); i++) {
            hashMap[inorder[i]] = i;
        }

        return builder(inorder, 0, inorder.size() - 1, preorder, 0,
                       preorder.size() - 1, hashMap);
    }
};