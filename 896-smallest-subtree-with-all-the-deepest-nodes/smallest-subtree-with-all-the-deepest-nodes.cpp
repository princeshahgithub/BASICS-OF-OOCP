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
    // Bottom-up BFS
    vector<vector<TreeNode*>> get_bfs(TreeNode* root) {
        vector<vector<TreeNode*>> bfs;
        if (root == nullptr) return bfs;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            vector<TreeNode*> level;

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node);

                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }

            // insert at front to make it bottom-up
            bfs.insert(bfs.begin(), level);
        }

        return bfs;
    }

    // Recursive subtree search
    bool find(TreeNode* root, int target) {
        if (root == nullptr) return false;
        if (root->val == target) return true;

        return find(root->left, target) || find(root->right, target);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<vector<TreeNode*>> bfs = get_bfs(root);

        // collect deepest leaves' values
        vector<int> deepest_leaves;
        for (TreeNode* node : bfs[0]) {
            deepest_leaves.push_back(node->val);
        }

        // check from bottom to top
        for (auto& level : bfs) {
            for (TreeNode* node : level) {
                bool found_mem = true;

                for (int val : deepest_leaves) {
                    if (!find(node, val)) {
                        found_mem = false;
                        break;
                    }
                }

                if (found_mem)
                    return node;
            }
        }

        return nullptr;
    }
};