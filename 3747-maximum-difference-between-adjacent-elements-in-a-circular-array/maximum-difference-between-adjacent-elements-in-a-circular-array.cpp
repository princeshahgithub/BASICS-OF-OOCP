class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        const int n=nums.size();
        int ans=abs(nums[0]-nums[n-1]);
        for(int i=1; i<n; i++)
            ans=max(ans, abs(nums[i]-nums[i-1]));
        return ans;
    }
};