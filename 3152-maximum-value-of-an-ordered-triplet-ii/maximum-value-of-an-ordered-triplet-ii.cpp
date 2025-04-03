class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int maxi = INT_MIN, diff = 0, n = nums.size();
        long long res = 0;
        
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]); // Update the max value seen so far
            if (i >= 2)
                res = max(res, (long long)diff * nums[i]); // Compute max triplet value
            if (i >= 1)
                diff = max(diff, maxi - nums[i]); // Update max difference
        }
        
        return res;
    }
};