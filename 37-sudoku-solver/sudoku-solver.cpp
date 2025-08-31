class Solution {
public:
    bool canPlaceDigit(vector<vector<char>>& grid, int n, int i, int j, int d){
        // checks if we can place digit 'd' in the (i,j)th cell of the grid[][]
        for(int k=0; k<n; k++){
            if(grid[i][k] == d+'0' || grid[k][j] == d+'0'){     // row or column
                return false;
            }
        }

        // check if digit 'd' is in the same subgrid of (i, j)th cell
        int rn = sqrt(n);

        int sx = i/rn * rn;
        int sy = j/rn * rn;

        // OR

        // int sx = i - i%rn;
        // int sy = j - j%rn;

        for(int x=sx; x<(sx+rn); x++){
            for(int y=sy; y < (sy + rn); y++){
                if(grid[x][y] == d+'0'){
                    return false;
                }
            }
        }

        return true;

    }

    bool helper(vector<vector<char>>& grid, int n, int i, int j){
        // base case
        if(i == n){
            // // all empty cells have been assigned valid digits
            // for (int i = 0; i < n; i++) {
            //     for (int j = 0; j < n; j++) {
            //         cout << grid[i][j] << " ";
            //     }
            //     cout << endl;
            // }
            // cout << endl;
            return true;
        }


        // recursive case

        if(j == n){
            // digits have been assigned to all the cells in the ith row -
            // move to the next row, and start filling from its 0th cell
            return helper(grid, n, i + 1, 0);
        }

        if(grid[i][j] != '.'){
            // (i, j)th cell is already assigned a digit -
            // move to the next cell at the (i, j+1)th idx
            return helper(grid, n, i, j + 1);
        }

        // assign a valid digit 'd' to the (i, j)th cell where 1<=d<=9
        for(int d=1; d<=9; d++){
            if(canPlaceDigit(grid, n, i, j, d)){
                char digit = d + '0';
                grid[i][j] = digit;
                if(helper(grid, n, i, j + 1)){
                    return true;
                }
                grid[i][j] = '.'; // backtracking
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {  // TC: O(9^(N*N)); N = 9
        helper(board, 9, 0, 0);
    }
};