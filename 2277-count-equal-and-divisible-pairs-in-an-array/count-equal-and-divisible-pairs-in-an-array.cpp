class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> pos;  // Map to store indices for each number
        int count = 0;
        
        // Step 1: Group numbers by their values (village)
        for (int i = 0; i < nums.size(); ++i) {
            // Step 2: Check only within the same group (same number)
            for (int j : pos[nums[i]]) {
                if ((i * j) % k == 0) {
                    count++;
                }
            }
            // Step 3: Add current index to the list for the number
            pos[nums[i]].push_back(i);
        }
        
        return count;
    }
};