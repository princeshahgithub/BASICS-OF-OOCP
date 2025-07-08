class Solution 
{
public:
    int maxValue(vector<vector<int>>& events, int k) 
    {
        // Step 1: Sort events by end time
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int n = events.size();

        // Step 2: Initialize DP table
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        // Step 3: Loop through each event
        for (int i = 1; i <= n; ++i) 
        {
            int start = events[i - 1][0];
            int end = events[i - 1][1];
            int value = events[i - 1][2];

            // Step 4: Binary search for last event that ends before this one starts
            int prev = binarySearch(events, i - 1, start);

            // Step 5: Try all possible selection counts
            for (int j = 1; j <= k; ++j) 
            {
                // Option 1: Skip current
                // Option 2: Take current + best from prev
                dp[i][j] = max(dp[i - 1][j], dp[prev + 1][j - 1] + value);
            }
        }

        // Step 6: Return max value from all k selections
        return dp[n][k];
    }

private:
    // Binary Search: find last index with end < targetStart
    int binarySearch(const vector<vector<int>>& events, int right, int targetStart) 
    {
        int left = 0;
        int res = -1;
        
        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            if (events[mid][1] < targetStart) 
            {
                res = mid;
                left = mid + 1;
            } 
            else 
            {
                right = mid - 1;
            }
        }

        return res;
    }
};