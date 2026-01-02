class Solution {
public:
    int repeatedNTimes(vector<int>& arr) {
        // O(1) Space
        int n = arr.size();
        if(arr[0] == arr[1]) return arr[0];
        if(arr[0] == arr[2] || arr[1] == arr[2]) return arr[2];
        // Moore Voting Algorithm
        int ans, freq = 0;
        for(int i=3; i<n; i++){
            if(freq == 0) ans = arr[i];
            if(arr[i] == ans) freq++;
            else freq--;
        }
        return ans;
    }
};