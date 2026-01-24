class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        int res = 0;
        while (i < j){
            int pair_sum = nums[i] + nums[j];
            res = max(res, pair_sum);
            i++;
            j--;
        }
        return res;
    }
};