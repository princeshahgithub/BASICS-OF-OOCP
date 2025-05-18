class Solution 
{
    static const int MOD = 1000000007;

public:
    int colorTheGrid(int m, int n) 
    {
        // Step 1: Generate all valid columns
        vector<vector<int>> states;
        vector<int> current(m);
        generateStates(m, current, 0, states);

        // Step 2: Build transitions between states (compatible pairs)
        vector<vector<int>> transitions(states.size());
        for (int i = 0; i < (int)states.size(); i++) 
        {
            for (int j = 0; j < (int)states.size(); j++) 
            {
                if (isCompatible(states[i], states[j])) 
                {
                    transitions[i].push_back(j);
                }
            }
        }

        // Step 3: Initialize DP for the first column
        vector<long long> dp(states.size(), 1);

        // Step 4: DP over columns
        for (int col = 1; col < n; col++) 
        {
            vector<long long> newDp(states.size(), 0);
            for (int prev = 0; prev < (int)states.size(); prev++) 
            {
                if (dp[prev] == 0)
                {
                    continue;
                }
                
                for (int nxt : transitions[prev]) 
                {
                    newDp[nxt] = (newDp[nxt] + dp[prev]) % MOD;
                }
            }

            dp = move(newDp);
        }

        // Step 5: Sum all final configurations
        long long result = 0;
        for (long long val : dp)
        {
            result = (result + val) % MOD;
        }

        return (int)result;
    }

private:
    // Recursively generate all valid columns (no vertical same colors)
    void generateStates(int m, vector<int>& current, int row, vector<vector<int>>& states) 
    {
        if (row == m) 
        {
            states.push_back(current);
            return;
        }
        
        for (int color = 1; color <= 3; color++) 
        {
            if (row > 0 && current[row - 1] == color)
            {
                continue;
            } 
            
            current[row] = color;
            generateStates(m, current, row + 1, states);
        }
    }

    // Check if two columns are compatible horizontally (no same colors in any row)
    bool isCompatible(const vector<int>& a, const vector<int>& b) 
    {
        for (int i = 0; i < (int)a.size(); i++) 
        {
            if (a[i] == b[i])
            {
                return false;
            } 
        }
        
        return true;
    }
};