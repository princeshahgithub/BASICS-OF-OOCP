class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        dp[1] = 1; // Day 1: one person learns the secret

        for (int i = 1; i <= n; i++) {
            for (int j = i + delay; j < i + forget && j <= n; j++) {
                dp[j] = (dp[j] + dp[i]) % MOD;
            }
        }

        long long ans = 0;
        for (int i = n - forget + 1; i <= n; i++) {
            if (i >= 1)
                ans = (ans + dp[i]) % MOD;
        }
        return ans;
    }
};