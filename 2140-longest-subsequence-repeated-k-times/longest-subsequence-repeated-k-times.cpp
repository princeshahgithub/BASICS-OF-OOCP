class Solution {
public:
    int n, maxLen=0;
    bool repeatK(string& s, string& t, int m, int k){
        for (int i=0, j=0; i<n && k>0; i++) {
            if (s[i]==t[j]) {
                j++;
                if (j==m) {
                    k--;
                    j=0;
                }
            }
        }
    //    cout<<"k="<<k<<endl;
        return k==0;
    }

    string ans="";
    vector<char> chars;
    void dfs(string& s, string& t, int k){
        int m=t.size();
        if (m>maxLen) return;
        if (m>0 && !repeatK(s, t, m, k)) return;  
        if (m>ans.size()) ans=t;
        for (char c : chars){
            t.push_back(c);
            dfs(s, t, k);
            t.pop_back();// backtracking
        }
    }

    string longestSubsequenceRepeatedK(string& s, int k) {
        int freq[26]={0};
        bitset<26> hasX=0;
        for(char c: s){
            const int x=c-'a';
            if (++freq[x]==k)
                hasX[x]=1;
        }
        if (hasX==0) return "";

        // reuse s, rebuild the string s for c in s with freq[c-'a]>=k 
        // it's faster for checking if a subsequence is reapted k times
        int j=0;
        n=s.size();
        for(int i=0; i<n; i++){
            const int x=s[i]-'a';
            if (hasX[x]) s[j++]=s[i];
        }
        s.resize(j);
        n=j;
        maxLen=n/k;
        
        for(int i=25; i>=0; i--)// lexico large first
            if (hasX[i]) chars.push_back('a'+i);
        string t="";
        dfs(s, t, k);
    
        return ans;
    }
};