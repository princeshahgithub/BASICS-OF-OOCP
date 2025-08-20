class Solution {
public:
int countSquares(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int count = 0;

    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (matrix[i][j] == 1) 
            {
                int maxLen = min(m - i, n - j);
                for (int len = 1; len <= maxLen; len++) 
                {
                    bool valid = true;
                    for (int x = i; x < i + len; x++) 
                    {
                        for (int y = j; y < j + len; y++) 
                        {
                            if (matrix[x][y] == 0) 
                            {
                                valid = false;
                                break;
                            }
                        }
                        if (!valid) break;
                    }
                    if (valid) 
                    count++;
                    else break; 
                }
            }
        }
    }
    return count;
}
};