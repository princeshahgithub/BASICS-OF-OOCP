class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int ans = original;
        int hash[1001] = {0};
        for(int i = 0; i < nums.size(); i++) hash[nums[i]]++;
        while(ans <= 1000 && hash[ans] != 0) ans *= 2;
        return ans;
    }
};