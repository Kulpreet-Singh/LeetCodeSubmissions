/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "";
        string str = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == nullptr) {
                str += "#,";
            } else {
                str += to_string(node->val) + ",";
            }
            if (node != nullptr) {
                q.push(node->left);
                q.push(node->right);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "")
            return nullptr;
        stringstream inp(data);
        string str;
        getline(inp, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            getline(inp, str, ',');
            if (str != "#") {
                TreeNode* left = new TreeNode(stoi(str));
                node->left = left;
                q.push(left);
            }
            getline(inp, str, ',');
            if (str != "#") {
                TreeNode* right = new TreeNode(stoi(str));
                node->right = right;
                q.push(right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));