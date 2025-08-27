class Solution {
public:
    bool inrange(int i, int j, int n, int m){
        if(i >= 0 && i < n && j >= 0 && j < m)return true;
        return false;
    }
    //fl2 - turned or not.
    //fl - 2 or 0 (1 - 2, 0 - 0)
    int dp[501][501][2][5][2];
    int solve(vector<vector<int>>& g, int i, int j, int n, int m, int fl, int dir, int fl2){
        if(!inrange(i, j, n, m))return 0;

        if(fl && g[i][j] != 2)return 0;
        if(!fl && g[i][j] != 0)return 0;

        if(dp[i][j][fl][dir][fl2] != -1)return dp[i][j][fl][dir][fl2];

        int len;

        if(fl2){
            if(dir == 1){
                len = 1 + solve(g, i+1, j+1, n, m, !fl, 1, 1);
            } else if(dir == 2){
                len = 1 + solve(g, i+1, j-1, n, m, !fl, 2, 1);
            } else if(dir == 3){
                len = 1 + solve(g, i-1, j-1, n, m, !fl, 3, 1);
            } else if(dir == 4){
                len = 1 + solve(g, i-1, j+1, n, m, !fl, 4, 1);
            }
        } else {
            if(dir == 1){
                len = 1 + max(solve(g, i-1, j+1, n, m, !fl, 1, 0), solve(g, i+1, j+1, n, m, !fl, 1, 1));
            } else if(dir == 2){
                len = 1 + max(solve(g, i+1, j+1, n, m, !fl, 2, 0), solve(g, i+1, j-1, n, m, !fl, 2, 1));
            } else if(dir == 3){
                len = 1 + max(solve(g, i+1, j-1, n, m, !fl, 3, 0), solve(g, i-1, j-1, n, m, !fl, 3, 1));
            } else if(dir == 4){
                len = 1 + max(solve(g, i-1, j-1, n, m, !fl, 4, 0), solve(g, i-1, j+1, n, m, !fl, 4, 1));
            }
        }

        return dp[i][j][fl][dir][fl2] = len;
    }
    int go_diag_give_max(vector<vector<int>>& g, int i, int j, int n, int m){

        return max({solve(g, i-1, j+1, n, m, 1, 1, 0), solve(g, i+1, j+1, n, m, 1, 2, 0), 
        solve(g, i+1, j-1, n, m, 1, 3, 0), solve(g, i-1, j-1, n, m, 1, 4, 0)});

    }
    int lenOfVDiagonal(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        memset(dp, -1, sizeof(dp));

        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(g[i][j] == 1){
                    int val = go_diag_give_max(g, i, j, n, m);
                    ans = max(ans, val+1);
                }
            }
        }

        return ans;
    }
};