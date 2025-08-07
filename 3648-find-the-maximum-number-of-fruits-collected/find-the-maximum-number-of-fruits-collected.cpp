int dp[1000][1000];
class Solution {
public:
    int n;
    // cannot obtain fruits from the upper left triangle region
    // initialize once, 3 children can only intersect at (n-1, n-1)
    // fill with 0 for the upper left triangle region, other with -1
    void init(){
        for(int i=0; i<n; i++){
            fill(dp[i], dp[i]+(n-1-i), 0);
            fill(dp[i]+(n-1-i), dp[i]+n, -1);
        }
    }
    int f2(int i, int  j, vector<vector<int>>& fruits){
        if (i<0 || i>=n || j<0 || j>=n) return 0;
        if (dp[i][j]!=-1) return dp[i][j];
    //    if (i>=j) return dp[i][j]=0;
        // if (i+j<n-1) return dp[i][j]=0;
        return dp[i][j]=fruits[i][j]+max(f2(i-1, j-1, fruits), max(f2(i-1, j, fruits), f2(i-1, j+1, fruits)));  
    }
    
    int f3(int i, int  j, vector<vector<int>>& fruits){
        if (i<0 || i>=n || j<0 || j>=n) return 0;
        if (dp[i][j]!=-1) return dp[i][j];
    //    if (i<=j) return dp[i][j]=0;
        // if (i+j<n-1)  return dp[i][j]=0;
        return dp[i][j]=fruits[i][j]+max(f3(i-1, j-1, fruits), max(f3(i, j-1, fruits), f3(i+1, j-1, fruits)));  
    }
    
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n=fruits.size();
        int diag=0;
        for(int i=0; i<n; i++)
            diag+=fruits[i][i];
        init();
        int child3=f3(n-1, n-2, fruits);
    
        return diag+child3+f2(n-2, n-1, fruits);
    }
};