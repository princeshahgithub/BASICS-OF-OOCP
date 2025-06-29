class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int mod=1e9+7;
        int freq[1000001]={0}, xMax=0;
        for(int x: nums){
            freq[x]++;
            xMax=max(x, xMax);
        }
        int n=nums.size(); 
        for(int x=1, i=0; x<=xMax; x++){
            const int f=freq[x];
            if (f==0) continue;
            fill(nums.begin()+i, nums.begin()+i+f, x);
            i+=f;
        }   

        vector<int> pow2mod(n+1, 1);
        for (int exp=1; exp<=n; exp++)
            pow2mod[exp]=(pow2mod[exp-1]<<1)%mod;
        
        int ans=0;
        for(int l=0, r=n-1; l<=r; ){
            if( nums[l]+nums[r]<=target){
                ans+=pow2mod[r-l];// % mod is costly 
                if (ans>=mod) ans-=mod;
                l++;
            }
            else{
                // binary method is not so efficient
                //r=upper_bound(nums.begin()+l, nums.begin()+r, target-nums[l])-nums.begin()-1;
                r--;// this is even better
            }
        }
        return ans;
    }
};