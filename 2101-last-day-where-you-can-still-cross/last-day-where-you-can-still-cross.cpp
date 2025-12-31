class Solution {
public:
    int totalRows, totalCols;
    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

    bool canCrossOnDay(int day, vector<vector<int>>& cells) {
        vector<vector<int>> grid(totalRows, vector<int>(totalCols, 0));

        for (int i = 0; i < day; i++) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = 1;
        }

        queue<pair<int,int>> bfsQueue;
        vector<vector<bool>> visited(totalRows, vector<bool>(totalCols, false));

        for (int col = 0; col < totalCols; col++) {
            if (grid[0][col] == 0) {
                bfsQueue.push({0, col});
                visited[0][col] = true;
            }
        }

        while (!bfsQueue.empty()) {
            auto [currentRow, currentCol] = bfsQueue.front();
            bfsQueue.pop();

            if (currentRow == totalRows - 1) return true;

            for (auto& dir : directions) {
                int nextRow = currentRow + dir[0];
                int nextCol = currentCol + dir[1];

                if (nextRow >= 0 && nextRow < totalRows &&
                    nextCol >= 0 && nextCol < totalCols &&
                    !visited[nextRow][nextCol] &&
                    grid[nextRow][nextCol] == 0) {

                    visited[nextRow][nextCol] = true;
                    bfsQueue.push({nextRow, nextCol});
                }
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        totalRows = row;
        totalCols = col;

        int left = 1;
        int right = cells.size();
        int answer = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canCrossOnDay(mid, cells)) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return answer;
    }
};

static const auto speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();