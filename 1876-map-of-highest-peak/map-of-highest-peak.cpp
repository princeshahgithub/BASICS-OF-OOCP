class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int R = isWater.size();
        int C = isWater[0].size();
        vector<vector<int>> height(R, vector<int>(C, R + C)); // Initialize with a safe sentinel value

        // First pass: set water cells to 0 and propagate height from top-left to bottom-right
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (isWater[i][j] == 1) {
                    height[i][j] = 0; // Water cell has height 0
                } else {
                    if (i > 0) 
                        height[i][j] = min(height[i][j], height[i - 1][j] + 1); // Check from top
                    if (j > 0) 
                        height[i][j] = min(height[i][j], height[i][j - 1] + 1); // Check from left
                }
            }
        }

        // Second pass: propagate height from bottom-right to top-left
        for (int i = R - 1; i >= 0; i--) {
            for (int j = C - 1; j >= 0; j--) {
                if (i < R - 1) 
                    height[i][j] = min(height[i][j], height[i + 1][j] + 1); // Check from bottom
                if (j < C - 1) 
                    height[i][j] = min(height[i][j], height[i][j + 1] + 1); // Check from right
            }
        }

        return height;
    }
};