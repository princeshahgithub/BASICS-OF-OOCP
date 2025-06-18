class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); i += 3) {
            if (i + 2 >= nums.size() || nums[i + 2] - nums[i] > k) return {};
            result.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }

        return result;
    }
};