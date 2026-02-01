class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = nums[0];  
        sort(nums.begin()+1 , nums.end()); 
        ans += nums[1]; 
        ans += nums[2]; 
        return ans;
    }
};