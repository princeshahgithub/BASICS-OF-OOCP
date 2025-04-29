class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long res = 0;
        int max_element = 0, maxi_count = 0;

        for (int i = 0; i < nums.size(); i++) {
            max_element = max(max_element, nums[i]);
        }

        for (int right = 0, left = 0; right < nums.size(); right++) {
            if (nums[right] == max_element)
                maxi_count++;
            while (maxi_count == k) {
                res += nums.size() - right;
                if (nums[left] == max_element)
                    maxi_count--;
                left++;
            }
        }

        return res;
    }
};