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
    TreeNode* builder(vector<int>& inorder, int is, int ie,
                      vector<int>& postorder, int ps, int pe,
                      map<int, int>& hashMap) {
        if (is > ie || ps > pe) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(postorder[pe]);
        int inRoot = hashMap[postorder[pe]];
        int numLeft = inRoot - is;

        root->left = builder(inorder, is, inRoot - 1, postorder, ps,
                             ps + numLeft - 1, hashMap);

        root->right = builder(inorder, inRoot + 1, ie, postorder, ps + numLeft,
                              pe - 1, hashMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size()) {
            return nullptr;
        }
        map<int, int> hashMap;
        for (int i = 0; i < inorder.size(); i++) {
            hashMap[inorder[i]] = i;
        }

        return builder(inorder, 0, inorder.size() - 1, postorder, 0,
                       postorder.size() - 1, hashMap);
    }
};