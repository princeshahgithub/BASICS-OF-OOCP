class Solution {
public:
    #define p pair<int, int>
    bool isValid(int r, int c, int n, int m, vector<vector<int>>& vis) {
        return r >= 0 && c >= 0 && r < n && c < m && vis[r][c] == 0;
    }

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int, p>, vector<pair<int, p>>, greater<pair<int, p>>> pq;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int d = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if (vis[r][c]) continue;
            vis[r][c] = 1;
            if (r == n - 1 && c == m - 1) {
                return d;
            }
            int dir = grid[r][c] - 1;
            int nr = r + directions[dir][0];
            int nc = c + directions[dir][1];
            if (isValid(nr, nc, n, m, vis)) {
                pq.push({d, {nr, nc}});
            }
            for (int i = 0; i < 4; i++) {
                if (i == dir) continue;
                nr = r + directions[i][0];
                nc = c + directions[i][1];
                if (isValid(nr, nc, n, m, vis)) {
                    pq.push({d + 1, {nr, nc}});
                }
            }
        }
        return -1;
    }
};