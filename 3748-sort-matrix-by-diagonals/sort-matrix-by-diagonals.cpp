class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) {
            return grid;
        }

        // Sort diagonals starting from first column in descending order
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            int row = i;
            for (int col = 0; col < n - i; col++) {
                temp.push_back(grid[row][col]);
                row++;
            }
            sort(temp.begin(), temp.end(), greater<int>());
            row = i;
            for (int col = 0; col < n - i; col++) {
                grid[row][col] = temp[col];
                row++;
            }
        }

        // Sort diagonals starting from first row in ascending order
        for (int j = 1; j < n; j++) {
            vector<int> temp;
            int col = j;
            for (int row = 0; row < n - j; row++) {
                temp.push_back(grid[row][col]);
                col++;
            }
            sort(temp.begin(), temp.end());
            col = j;
            for (int row = 0; row < n - j; row++) {
                grid[row][col] = temp[row];
                col++;
            }
        }

        return grid;
    }
};