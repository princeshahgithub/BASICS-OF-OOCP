class Solution {
public:
    static int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size(), ans=0;
        for(int i=2; i<n; i++){
            int l=0, r=i-1;
            while(l<r){
                if(nums[l]+nums[r]>nums[i]){
                    ans+=r-l;
                    r--;
                }
                else l++;
            }
        }
        return ans;
    }
};


auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();