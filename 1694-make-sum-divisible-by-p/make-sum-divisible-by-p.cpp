class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int rem = accumulate(nums.begin(), nums.end(), 0LL) % p, pre = 0, res = nums.size();
        if (!rem) return 0;
        unordered_map<int, int> mp = {{0, -1}};
        for (int i = 0; i < nums.size(); ++i) {
            pre = (pre + nums[i]) % p;
            if (mp.count((pre - rem + p) % p)) 
                res = min(res, i - mp[(pre - rem + p) % p]);
            mp[pre] = i;
        }
        return res == nums.size() ? -1 : res;
    }
};
auto io_opt = [] { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();