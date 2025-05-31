class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        auto getCoordinates = [n](int pos) {
            int r = (pos - 1) / n, c = (pos - 1) % n;
            int row = n - 1 - r;
            int col = (r % 2 == 0) ? c : (n - 1 - c);
            return make_pair(row, col);
        };

        queue<pair<int, int>> q;  // (pos, moves)
        unordered_set<int> visited;
        q.push({1, 0});
        visited.insert(1);

        while (!q.empty()) {
            auto [pos, moves] = q.front(); q.pop();
            for (int i = 1; i <= 6; ++i) {
                int next = pos + i;
                if (next > n * n) continue;
                auto [r, c] = getCoordinates(next);
                if (board[r][c] != -1) {
                    next = board[r][c];
                }
                if (next == n * n) return moves + 1;
                if (!visited.count(next)) {
                    visited.insert(next);
                    q.push({next, moves + 1});
                }
            }
        }
        return -1;
    }
};