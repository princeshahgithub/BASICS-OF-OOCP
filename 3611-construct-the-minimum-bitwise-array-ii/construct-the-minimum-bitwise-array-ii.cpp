class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int currPosition = 1;   // start checking bits from the LSB
            int ans = -1;

            while ((nums[i] & currPosition) != 0) {  // move until we encounter a 0 bit
                ans = nums[i] - currPosition;        // remove the current 1 bit
                currPosition = currPosition << 1; // keep moving left
            }
            nums[i] = ans;
        }
        return nums;
    }
};