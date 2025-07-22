class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> lastIndex;
        int start = 0, max_sum = 0, current_sum = 0;
        for (int end = 0; end < nums.size(); ++end) {
            int num = nums[end];
            if (lastIndex.count(num) && lastIndex[num] >= start) {
                int prevIndex = lastIndex[num];
                for (int i = start; i <= prevIndex; ++i) {
                    current_sum -= nums[i];
                }
                start = prevIndex + 1;
            }
            current_sum += num;
            max_sum = max(max_sum, current_sum);
            lastIndex[num] = end;
        }
        return max_sum;
    }
};