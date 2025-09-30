class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        int start=0, end=n-1;
        while(start<end) {
            for(int i=start; i<end; i++) {
                nums[i] = (nums[i]+nums[i+1])%10;
            }
            end--;
        }
        return nums[0];
    }
};