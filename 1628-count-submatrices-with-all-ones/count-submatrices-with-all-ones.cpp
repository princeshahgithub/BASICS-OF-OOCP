class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        int total = 0;

        // prefix sums rows wise
        for (int i = 0; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (mat[i][j])
                    mat[i][j] += mat[i][j - 1];
            }
        }

        // count submatrices 
        for(int i = 0; i<row; i++)
        {
            for(int j = 0; j<col; j++)
            {
                int minWidth = mat[i][j];
                for(int k = i; k >=0 && mat[k][j]; k--)
                {
                    minWidth = min(minWidth, mat[k][j]);
                    total += minWidth;
                }
            }
        }

        return total;
    }
};