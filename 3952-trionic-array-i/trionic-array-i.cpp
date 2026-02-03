class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = (int)nums.size();
        auto isIncreasing = [&](int l, int r) -> bool{
            for(int i = l; i < r; i ++){
                if(nums[i] >= nums[i + 1]) return false;
            }
            return true;
        };
        auto isDecreasing = [&](int l, int r) -> bool{
            for(int i = l; i < r; i ++){
                if(nums[i] <= nums[i + 1]) return false;
            }
            return true;
        };
        for(int p = 1; p < n - 2; p ++){
            for(int q = p + 1; q < n - 1; q ++){
                if(isIncreasing(0, p) && isDecreasing(p, q) && isIncreasing(q, n-1)){
                    return true;
                }
            }
        }
        return false;
    }
};