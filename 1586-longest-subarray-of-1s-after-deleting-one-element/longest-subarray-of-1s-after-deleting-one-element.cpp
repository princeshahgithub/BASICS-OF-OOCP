class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        const int n=nums.size();
        int zeros=0, ans=0;
        for(int l=0, r=0; r<n; r++){
            zeros+=(nums[r]==0);
            zeros-=(zeros>1 && nums[l++]==0);
            ans=max(ans, r-l);
        }
        return ans; 
    }
};