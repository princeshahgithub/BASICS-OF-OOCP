class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int total = 0;
        for (int num : nums) {
            total |= num;  // Step 1: Compute bitwise OR of all numbers
        }
        return total * (1 << (nums.size() - 1));  // Step 2: Multiply by 2^(n-1)
    }
};