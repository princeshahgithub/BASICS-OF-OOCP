class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        unordered_map<int, vector<int>> mp;
        vector<int> ans;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }

        // traversing the diagonal and preserving its order
        for(int d = 0; d < n+m-1; d++){
            if(d%2 == 0) {
                reverse(mp[d].begin(), mp[d].end()); // reverse order of even diagonals for zig-zag
            }
            ans.insert(ans.end(), mp[d].begin(), mp[d].end());
        }
        
        return ans;
    }
};