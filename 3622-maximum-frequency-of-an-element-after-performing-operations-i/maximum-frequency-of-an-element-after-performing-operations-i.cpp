class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        // Difference array for range updates
        vector<int> diff(2 * 1e5 + 5, 0);
        unordered_map<int, int> freq;
        int maxFreq = -1;
        int maxEle = -1;

        // Step 1 & 2: Build difference array and track frequencies
        for (auto ele : nums) {
            // Each element can be transformed to range [ele-k, ele+k]
            int mini = ele - k;
            int maxi = ele + k;

            // Mark range in difference array
            if (mini < 0) 
                diff[0]++;
            else  
                diff[mini]++;
            
            diff[maxi + 1]--;
            
            // Track original frequency
            freq[ele]++;
            maxFreq = max(maxFreq, freq[ele]);
            maxEle = max(maxEle, ele);
        }

        // Step 3 & 4: Compute prefix sum and find maximum achievable frequency
        int maxiAns = 0;
        for (int i = 1; i <= maxEle + numOperations; i++) {
            // Convert difference array to actual counts
            diff[i] += diff[i - 1];
            
            // Maximum frequency at value i:
            // min(elements that can reach i, original elements at i + operations)
            maxiAns = max(maxiAns, min(diff[i], freq[i] + numOperations));
        }

        // Step 5: Consider just boosting the most frequent element
        int ans = min(maxiAns, maxFreq + numOperations);
        return ans;
    }
};