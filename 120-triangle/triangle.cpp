// Memoization

// class Solution {
// public:
//     int helper(int r, int i, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
//         // Base: last row
//         if (r == triangle.size() - 1) return triangle[r][i];
        
//         // Already computed
//         if (dp[r][i] != -1) return dp[r][i];
        
//         // Recurse: move to (r+1,i) and (r+1,i+1)
//         int down = helper(r+1, i, triangle, dp);
//         int diag = helper(r+1, i+1, triangle, dp);
        
//         return dp[r][i] = triangle[r][i] + min(down, diag);
//     }

//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         vector<vector<int>> dp(n, vector<int>(n, -1));
//         return helper(0, 0, triangle, dp);
//     }
// };

// *********************************************************************

// Tabulation

// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         vector<vector<int>> dp(n, vector<int>(n, 0));

//         // Base case: last row = same as triangle
//         for (int i = 0; i < n; i++) {
//             dp[n - 1][i] = triangle[n - 1][i];
//         }

//         // Fill DP table from bottom-2 row to top
//         for (int r = n - 2; r >= 0; r--) {
//             for (int i = 0; i < triangle[r].size(); i++) {
//                 int down = dp[r + 1][i];
//                 int diag = dp[r + 1][i + 1];
//                 dp[r][i] = triangle[r][i] + min(down, diag);
//             }
//         }

//         return dp[0][0];
//     }
// };

// *********************************************************************

// Space Optimized

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(triangle.back()); // start with last row

        // Iterate from second last row to top
        for (int r = n - 2; r >= 0; r--) {
            for (int i = 0; i < triangle[r].size(); i++) {
                dp[i] = triangle[r][i] + min(dp[i], dp[i+1]);
            }
        }

        return dp[0]; // minimum path sum
    }
};