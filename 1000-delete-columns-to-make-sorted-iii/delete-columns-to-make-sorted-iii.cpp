class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int l = strs[0].length();
        int n = strs.size();
        vector<int> dp(l, 1);
        int maxlen = 0;
        for(int i = 0; i < l; i++){
            for(int j = 0; j < i; j++){
                bool check = true;
                for(int k = 0; k < n; k++){
                    if(strs[k][j] > strs[k][i]){
                        check = false;
                        break;
                    }
                }
                if(check){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxlen = max(maxlen, dp[i]);
        }

        return l - maxlen;
    }
};