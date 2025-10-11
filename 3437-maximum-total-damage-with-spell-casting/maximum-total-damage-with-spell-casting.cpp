class Solution {
public:
    using info=pair<int, long long>;// (power, damage)
    long long dp[100001];
    int sz;
    long long f(int i, vector<info>& spell){
        if (i>=sz) return 0;
        if (dp[i]!=-1) return dp[i];

        long long notake=f(i+1, spell);

        long long take=0;
        int j=i+1,  x=spell[i].first;
        for(; j<sz && spell[j].first<=x+2; j++);

        take=spell[i].second+f(j, spell);
        
        return dp[i]=max(take, notake);
    }

    long long maximumTotalDamage(vector<int>& power) {
        const int n=power.size();
        sort(power.begin(), power.end());

        vector<info> spell={{power[0], power[0]}};
        for(int i=1; i<n; i++){
            int x=power[i]; 
            if (x!=power[i-1]) spell.emplace_back(x, (long long)x);
            else spell.back().second+=x;
        }
        sz=spell.size();

        fill(dp, dp+sz, -1);
        return f(0, spell);
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();