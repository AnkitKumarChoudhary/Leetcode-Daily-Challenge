class Solution {
public:
    static int maxLevelSum(const TreeNode* root) noexcept {
        queue<const TreeNode*> q;
        q.push(root);
        int lvl = 1;
        int maxLvl = 1;
        int maxSum = root->val;

        for (; !q.empty(); ++lvl) {
            int endLvl = q.size();
            int sum = 0;
            for (int i = 0; i < endLvl; ++i) {
                const TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (sum > maxSum) {
                maxSum = sum;
                maxLvl = lvl;
            }
        }
        return maxLvl;
    }
};