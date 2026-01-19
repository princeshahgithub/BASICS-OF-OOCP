class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();

        vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pref[i][j] =
                    mat[i-1][j-1]
                  + pref[i-1][j]
                  + pref[i][j-1]
                  - pref[i-1][j-1];
            }
        }

        int maxSide = min(m, n);

        while (maxSide > 0) {
            for (int i = 0; i + maxSide <= m; i++) {
                for (int j = 0; j + maxSide <= n; j++) {
                    int sum =
                        pref[i+maxSide][j+maxSide]
                      - pref[i][j+maxSide]
                      - pref[i+maxSide][j]
                      + pref[i][j];
                    if (sum <= threshold) return maxSide;
                }
            }
            maxSide--;
        }
        return 0;
    }
};