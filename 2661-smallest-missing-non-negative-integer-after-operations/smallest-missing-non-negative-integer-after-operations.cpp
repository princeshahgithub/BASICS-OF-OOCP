class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> freq;
        for(auto x : nums){
            int remainder = ((x% value) + value)%value;
            freq[remainder]++;
        }
        int MEX = 0 ;

        while(true){
            int r = MEX % value;
            if(freq[r] > 0){
                freq[r]--;
                MEX++;
            } 
            else{
                break;
            }
        }
        return MEX;
    }
};