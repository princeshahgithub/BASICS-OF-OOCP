class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;

        std::queue<TreeNode*> q;
        q.push(root);

        long long maxi = -1e18; 
        int curr_lvl = 1;
        int ans = 1;

        while (!q.empty()) {
            int size = q.size();
            long long curr_sum = 0;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                curr_sum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (curr_sum > maxi) {
                maxi = curr_sum;
                ans = curr_lvl;
            }

            curr_lvl++;
        }

        return ans;
    }
};