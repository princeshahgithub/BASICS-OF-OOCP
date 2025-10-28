class Solution {
public:
    int k(vector<int> &nums , int i, int direction , int zeroCount){
        if(zeroCount == nums.size()) return 1;
        if(i < 0 || i >= nums.size()) return 0;
        int ans = 0;
        if(nums[i] == 0){
            ans = k(nums, i + direction , direction, zeroCount);
        }
        else{
            int old  = nums[i];
            if(nums[i] == 1)zeroCount++;
            nums[i]--;
            direction *= -1;
            ans = k(nums, i + direction, direction , zeroCount );
            nums[i] = old; 
        }
        return ans;
    
    }
    int countValidSelections(vector<int>& nums) {
        int ans = 0;
        int zeroCount = 0;
        for(int i = 0 ; i < nums.size() ;i++){
            if(nums[i] == 0  ) zeroCount++;
        }
        for(int i = 0 ; i < nums.size() ; i++){
            
            if(nums[i] == 0){
                ans += k(nums, i, 1, zeroCount );
                ans += k(nums, i, -1, zeroCount );

            }
        }
        return ans;
    }
};