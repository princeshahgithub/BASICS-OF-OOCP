class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int>mp;
        int maxCount = 0;
        int count = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
            maxCount = max(maxCount, mp[nums[i]]);
        }
        
        for(auto i : mp)
        {
            if(i.second == maxCount)
            {
                count += i.second;
            }
        }
        return count;
    }
};