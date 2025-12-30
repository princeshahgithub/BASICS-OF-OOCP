class Solution {
public:
    static bool isMagic(int i, int j, int a, int b, int c, int d, 
        vector<vector<int>>& grid){
        // Check sums without through center, In fact like solving linear system
        return (a+grid[i-1][j]+b==15) &&
        (a+grid[i][j-1]+c==15) && (b+grid[i][j+1]+d==15) &&
        (c+grid[i+1][j]+d==15);
    }

    static int numMagicSquaresInside(vector<vector<int>>& grid) {
        const int r = grid.size(), c = grid[0].size();
        constexpr unsigned cornerMask=(1<<2)|(1<<4)|(1<<6)|(1<<8);
        if (r < 3 || c < 3) return 0;

        int cnt=0;
        for(int i=1; i < r-1; i++) {
            for(int j=1; j < c-1; j++) {
                // center is not 5
                if (grid[i][j]!=5) continue;
                int a=grid[i-1][j-1], b=grid[i-1][j+1], c=grid[i+1][j-1], d=grid[i+1][j+1];
                unsigned corner=(1<<a)|(1<<b)|(1<<c)|(1<<d);
                // check diagonals & center, numbers in corner are 2,4,6,8
                if (corner==cornerMask && a+d==10 && b+c==10 ) 
                    cnt+=isMagic(i, j, a,b,c,d, grid);
            }
        }
        return cnt;
    }
};





auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();