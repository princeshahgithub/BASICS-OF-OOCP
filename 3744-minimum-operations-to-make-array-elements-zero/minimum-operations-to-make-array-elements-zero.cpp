class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        vector<long long> p(16);
        p[0] = 1;

        // Precompute powers of 4 up to 4^15
        for (int i = 1; i < 16; i++) p[i] = p[i - 1] * 4;

        for (const auto& q : queries) {
            long long l = q[0], r = q[1], sum = 0;
            // Iterate over powers of 4 to compute operations
            for (int t = 1; t <= 15; t++) {
                long long L = max(l, p[t - 1]);
                long long R = min(r, p[t] - 1);
                if (L <= R) sum += t * (R - L + 1);
            }
            ans += (sum + 1) / 2;
        }
        return ans;
    }
};