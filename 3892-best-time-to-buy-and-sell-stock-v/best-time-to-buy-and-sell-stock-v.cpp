class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        long long l = 0, r = 1e9 + 7, ans = 0;
        int n = prices.size();

        while (l <= r) {
            long long mid = l + (r - l) / 2;
            
            // State: {profit, -transaction_count}
            // We use negative count so std::max prefers FEWER transactions
            // (e.g., -1 > -3, so count 1 is preferred over count 3)
            pair<long long, int> neutral = {0, 0};
            pair<long long, int> held = {-prices[0], 0};
            pair<long long, int> shorted = {prices[0], 0};

            for (int i = 1; i < n; ++i) {
                pair<long long, int> next_neutral = max({
                    neutral,
                    // Close Long: Add price, subtract penalty, decrement negative count (add 1 to real count)
                    {held.first + prices[i] - mid, held.second - 1},      
                    // Close Short: Sub price, subtract penalty, decrement negative count
                    {shorted.first - prices[i] - mid, shorted.second - 1} 
                });

                pair<long long, int> next_held = max(held, {neutral.first - prices[i], neutral.second});
                pair<long long, int> next_shorted = max(shorted, {neutral.first + prices[i], neutral.second});

                neutral = next_neutral;
                held = next_held;
                shorted = next_shorted;
            }

            // neutral.second is negative count. -neutral.second is real count.
            if (-neutral.second <= k) {
                ans = neutral.first + mid * k;
                r = mid - 1; // Try to reduce penalty to approach k
            } else {
                l = mid + 1; // Too many transactions, increase penalty
            }
        }
        return ans;
    }
};