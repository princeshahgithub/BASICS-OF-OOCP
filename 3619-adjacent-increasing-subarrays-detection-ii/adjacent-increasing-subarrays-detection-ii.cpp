class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

        int ans = 1;
        int k = 1, cnt = 1;

        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1]) {
                cnt++;
                continue;
            }
            ans = max({ans,cnt/2,min(k,cnt)});
            k = cnt;
            cnt = 1;
        }
        ans = max({ans,cnt/2,min(k,cnt)});
        return ans;
    }
};