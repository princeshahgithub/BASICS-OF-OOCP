class Solution {
public:
    int minScore(vector<int>& v , int i , int j , vector<vector<int>>& dp) {
        if (j - i <= 1) return 0;
        if (j - i == 2) return v[i] * v[i + 1] * v[j];
        if (dp[i][j] != -1) return dp[i][j];

        int score = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            score = min(score , minScore(v , i , k , dp) + v[i] * v[k] * v[j] + minScore(v , k , j , dp));
        }
        return dp[i][j] = score;
    }

    int minScoreTriangulation(vector<int>& values) {
        const int n = values.size();
        vector<vector<int>> dp(n , vector<int>(n , -1));

        return minScore(values , 0 , n - 1 , dp);
    }
};