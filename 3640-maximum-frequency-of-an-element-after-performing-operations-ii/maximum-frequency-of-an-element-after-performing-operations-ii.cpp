class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        if (n == 0) return 0;
        sort(nums.begin(), nums.end());

        // 1) For targets equal to existing nums[i]:
        // For each distinct value v, coverage_count(v) = number of nums within [v-k, v+k].
        int ans = 0;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && nums[j] == nums[i]) ++j;
            int count_equal = j - i;         // number of elements exactly == v
            long long v = nums[i];

            // window_size = count of elements within [v-k, v+k]
            int left_idx = int(lower_bound(nums.begin(), nums.end(), v - k) - nums.begin());
            int right_idx = int(upper_bound(nums.begin(), nums.end(), v + k) - nums.begin());
            int window_size = right_idx - left_idx;

            // We can convert at most numOperations of the non-equal elements in the window
            int freq_for_v = min(window_size, count_equal + numOperations);
            ans = max(ans, freq_for_v);

            i = j;
        }

        // 2) For targets not necessarily in nums:
        // compute maximum overlap of intervals [nums[t]-k, nums[t]+k] (sweep line).
        // If we pick a target v that no element originally equals, we can convert only by using operations,
        // so freq = min(max_overlap, numOperations).
        vector<long long> starts(n), ends(n);
        for (int t = 0; t < n; ++t) {
            starts[t] = (long long)nums[t] - k;
            ends[t]   = (long long)nums[t] + k;
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int s = 0, e = 0;
        int curr = 0;
        int maxOverlap = 0;
        while (s < n && e < n) {
            if (starts[s] <= ends[e]) {
                ++curr;
                maxOverlap = max(maxOverlap, curr);
                ++s;
            } else {
                --curr;
                ++e;
            }
        }
        // If any remaining starts (though loop condition handles), consume them
        while (s < n) { ++curr; maxOverlap = max(maxOverlap, curr); ++s; }
        // remaining ends would only decrease curr; not needed for max.

        ans = max(ans, min(maxOverlap, numOperations));

        return ans;
    }
};