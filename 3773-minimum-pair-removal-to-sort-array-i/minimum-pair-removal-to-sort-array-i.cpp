class Solution {
public:
    void shiftLeft(vector<int>& nums,int idx){
        int n=nums.size();
        for(int i=idx+1;i<n-1;i++){
            nums[i]=nums[i+1];
        }
        nums.pop_back();
    }
    void merge(vector<int>& nums){
        int n = nums.size();
        int mini = INT_MAX;
        int idx = 0;
        int minSum = 0;
        for(int i = 0; i < n - 1; i++){
            int sum = nums[i] + nums[i + 1];
            if(sum < mini){
                mini = sum;
                idx = i;
                minSum = sum; 
            }
        }
        nums[idx] = minSum;
        shiftLeft(nums, idx);
    }

    bool sorted(vector<int>& nums){
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i+1]<nums[i]) return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums){
        int n=nums.size();
        int result=0;
        while(!sorted(nums)){
            merge(nums);
            result++;
        }
        return result;
    }
};