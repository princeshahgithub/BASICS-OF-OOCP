class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int,int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        auto dfs = [&](int r, int c, int mid, vector<vector<bool>>& seen, auto& dfs_ref) -> bool {
            if (r == m-1 && c == n-1) return true;
            seen[r][c] = true;
            
            for (auto [dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !seen[nr][nc]) {
                    if (grid[nr][nc] <= mid) {
                        if (dfs_ref(nr, nc, mid, seen, dfs_ref)) return true;
                    }
                }
            }
            return false;
        };
        
        auto possible = [&](int mid) {
            if (grid[0][0] > mid) return false;
            vector<vector<bool>> seen(m, vector<bool>(n, false));
            return dfs(0, 0, mid, seen, dfs);
        };
        
        int lo = grid[0][0], hi = 0;
        for (auto& row : grid)
            for (int val : row)
                hi = max(hi, val);
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (possible(mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};