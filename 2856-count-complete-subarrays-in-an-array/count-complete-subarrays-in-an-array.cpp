class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> distinctElements(nums.begin(), nums.end());
        int totalDistinct = distinctElements.size();
        int count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            unordered_set<int> currentSet;
            for (int j = i; j < n; ++j) {
                currentSet.insert(nums[j]);
                if (currentSet.size() == totalDistinct) {
                    count += (n - j);
                    break;
                }
            }
        }
        return count;
    }
};