class Solution {
public:
    const int mod = 1e9 + 7;
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n + 1, 0);
        vector<long long> prefix(n + 1, 0);

        dp[0] = 1;
        prefix[0] = 1;

        multiset<int> s;

        int j = 0;

        for (int i = 0; i < n; i++) {
            s.insert(nums[i]);

            while (j <= i && (*s.rbegin() - *s.begin()) > k) {
                s.erase(s.find(nums[j]));
                j++;
            }
            if (j > 0) {
                dp[i + 1] = (prefix[i] - prefix[j - 1]+mod)%mod;
            }

            else {
                dp[i + 1] = prefix[i]%mod;
            }

            prefix[i + 1] = (prefix[i] + dp[i + 1]) % mod;
        }

        return dp[n];
    }
};