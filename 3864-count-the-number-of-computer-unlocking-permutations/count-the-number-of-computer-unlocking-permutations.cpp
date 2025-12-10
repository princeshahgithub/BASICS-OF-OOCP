class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int mod = 1000000007;
        long ans = 1;
        for(int i = 1; i < complexity.size(); i++) {
            if(complexity[i] <= complexity[0]) return 0;
            else ans = (ans * i) % mod;
        }
        return ans;
    }
};