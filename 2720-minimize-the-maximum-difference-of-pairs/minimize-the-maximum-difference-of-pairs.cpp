class Solution 
{
public:
    int minimizeMax(vector<int>& nums, int p) 
    {
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        int low = 0;
        int high = nums.back() - nums.front();

        // Step 3: Binary search
        while (low < high) 
        {
            int mid = low + (high - low) / 2;

            if (canFormPairs(nums, p, mid)) 
            {
                high = mid;
            } 
            else 
            {
                low = mid + 1;
            }
        }

        // Step 5: Return answer
        return low;
    }

private:
    // Step 4: Greedy pair formation
    bool canFormPairs(const vector<int>& nums, int p, int maxDiff) 
    {
        int count = 0;
        for (int i = 1; i < nums.size() && count < p;) 
        {
            if (nums[i] - nums[i - 1] <= maxDiff) 
            {
                count++;
                i += 2;
            } 
            else 
            {
                i++;
            }
        }
        
        return count >= p;
    }
};