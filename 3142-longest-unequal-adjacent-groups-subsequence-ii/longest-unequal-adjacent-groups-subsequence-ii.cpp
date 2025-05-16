class Solution {
public:
    static bool hamming1(string& s, string& t){
        const int sz=s.size();
        if (sz!=t.size()) return 0;
        int diff=0;
        for (int i=0; i<sz && diff<2; i++)
            diff+=s[i]!= t[i];
        return diff== 1;
    }

    static vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        const int n=words.size();
        int maxLen=0, pos=-1;
        int* dp=(int*)alloca(n*4);
        fill(dp, dp+n, 1);
        int* prev=(int*)alloca(n*4);
        fill(prev, prev+n, -1);
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(groups[i]!=groups[j] && hamming1(words[i], words[j]) 
                && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                }
            }
            if(dp[i]>maxLen){
                maxLen=dp[i];
                pos=i;
            }
        }
        vector<string> ans(maxLen);
        for(; pos!=-1; pos=prev[pos]){
            ans[--maxLen]=words[pos];
        }
        return ans;
    }
};