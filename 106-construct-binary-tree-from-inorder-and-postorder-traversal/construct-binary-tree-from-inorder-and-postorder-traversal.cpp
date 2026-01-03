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
    TreeNode* helper(vector<int>& post, unordered_map<int,int>& inMap, int& idx, int start, int end) {
        if (start > end) return nullptr;
        int val = post[idx--];
        TreeNode* root = new TreeNode(val);
        int pos = inMap[val];
        root->right = helper(post, inMap, idx, pos + 1, end);
        root->left = helper(post, inMap, idx, start, pos - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inMap;
        for (int i = 0; i < inorder.size(); i++) inMap[inorder[i]] = i;
        int idx = postorder.size() - 1;
        return helper(postorder, inMap, idx, 0, inorder.size() - 1);
    }
};