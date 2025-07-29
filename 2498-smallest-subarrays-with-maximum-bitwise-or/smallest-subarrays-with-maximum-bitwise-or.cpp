class Solution 
{
public:
    vector<int> smallestSubarrays(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> result(n);

        // Step 2: Initialize latest array to track last seen position of each bit
        vector<int> latest(32, -1);

        // Step 3: Traverse the array from right to left
        for (int i = n - 1; i >= 0; --i) 
        {
            int farthest = i; // Default: subarray ends at i

            // Step 4: Update latest seen positions for bits set in nums[i]
            for (int b = 0; b < 32; ++b) 
            {
                if ((nums[i] >> b) & 1) 
                {
                    latest[b] = i;
                }

                // Step 5: For each bit, if seen, update farthest position needed
                if (latest[b] != -1) 
                {
                    farthest = max(farthest, latest[b]);
                }
            }

            // Step 6: Store the length of smallest subarray starting at i
            result[i] = farthest - i + 1;
        }

        // Step 7: Return the result array
        return result;
    }
};