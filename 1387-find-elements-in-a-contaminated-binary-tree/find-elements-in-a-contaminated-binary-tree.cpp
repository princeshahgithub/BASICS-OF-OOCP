class FindElements {
public:
    unordered_map<int, bool> mp;

    void recover(TreeNode* root) {
        if (root->left) {
            root->left->val = root->val * 2 + 1;
            mp[root->left->val] = true;
            recover(root->left);
        }
        if (root->right) {
            root->right->val = root->val * 2 + 2;
            mp[root->right->val] = true;
            recover(root->right);
        }
    }

    FindElements(TreeNode* root) {
        root->val = 0;
        mp[0] = true;
        recover(root);
    }
    
    bool find(int target) {
        return mp[target];
    }
};