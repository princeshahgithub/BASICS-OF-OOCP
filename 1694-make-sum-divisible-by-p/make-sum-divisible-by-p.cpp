class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (int x : nums) total += x;
        int need = total % p;
        if (need == 0) return 0;

        unordered_map<int,int> mp;
        mp[0] = -1;
        long long prefix = 0;
        int res = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            prefix = (prefix + nums[i]) % p;
            int target = (prefix - need + p) % p;
            if (mp.count(target)) res = min(res, i - mp[target]);
            mp[prefix] = i;
        }

        return res == nums.size() ? -1 : res;
    }
};