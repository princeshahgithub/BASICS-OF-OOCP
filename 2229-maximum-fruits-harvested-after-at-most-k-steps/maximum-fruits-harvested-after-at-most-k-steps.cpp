#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        if (n == 0) {
            return 0;
        }

        vector<int> positions(n);
        vector<long long> prefix_sum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            positions[i] = fruits[i][0];
            prefix_sum[i + 1] = prefix_sum[i] + fruits[i][1];
        }

        long long max_fruits = 0;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            long long pos_l = positions[left];
            long long pos_r = positions[right];

            // Calculate the minimum steps to cover the current window [pos_l, pos_r]
            long long cost = (pos_r - pos_l) + min(abs(startPos - pos_l), abs(startPos - pos_r));

            // If the cost is too high, shrink the window from the left
            while (left <= right && cost > k) {
                left++;
                if (left > right) break;
                pos_l = positions[left];
                cost = (pos_r - pos_l) + min(abs(startPos - pos_l), abs(startPos - pos_r));
            }

            // If the window is valid, calculate fruits and update max
            if (left <= right) {
                long long current_fruits = prefix_sum[right + 1] - prefix_sum[left];
                max_fruits = max(max_fruits, current_fruits);
            }
        }

        return static_cast<int>(max_fruits);
    }
};