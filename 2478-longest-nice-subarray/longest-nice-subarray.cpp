class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0;
        int res=0;
        int num=0;
        for(l=0;l<n;l++){
            while((num & nums[l])!=0){
                num^=nums[r];
                r++;
            }
            num|=nums[l];
            res=max(res,l-r+1);
        }
        return res;
    }
};