class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<int> dp(m + 1, 0);

        for (int j = m - 1; j >= 0; j--) {
            dp[j] = dp[j + 1] + s2[j];
        }

        for (int i = n - 1; i >= 0; i--) {
            int prev = dp[m];
            dp[m] += s1[i];

            for (int j = m - 1; j >= 0; j--) {
                int temp = dp[j];
                if (s1[i] == s2[j]) {
                    dp[j] = prev;
                } else {
                    dp[j] = min(
                        s1[i] + dp[j],
                        s2[j] + dp[j + 1]
                    );
                }
                prev = temp;
            }
        }
        return dp[0];
    }
};