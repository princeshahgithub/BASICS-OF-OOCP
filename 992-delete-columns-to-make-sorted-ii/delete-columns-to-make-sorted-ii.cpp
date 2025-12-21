class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size(), n = strs[0].size();
        vector<bool> sorted(m, false);
        int ans = 0;

        for (int col = 0; col < n; col++) {
            bool bad = false;

            for (int row = 1; row < m; row++) {
                if (sorted[row]) continue;

                if (strs[row - 1][col] > strs[row][col]) {
                    bad = true;
                    break;
                }
            }

            if (bad) {
                ans++;
                continue;
            }

            for (int row = 1; row < m; row++) {
                if (!sorted[row] &&
                    strs[row - 1][col] < strs[row][col]) {
                    sorted[row] = true;
                }
            }
        }

        return ans;
    }
};