class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for (int n : nums) maxOr |= n;
        return dfs(nums, 0, 0, maxOr);
    }

private:
    int dfs(vector<int>& nums, int i, int currOr, int maxOr) {
        if (i == nums.size()) return currOr == maxOr ? 1 : 0;
        int include = dfs(nums, i + 1, currOr | nums[i], maxOr);
        int exclude = dfs(nums, i + 1, currOr, maxOr);
        return include + exclude;
    }
};