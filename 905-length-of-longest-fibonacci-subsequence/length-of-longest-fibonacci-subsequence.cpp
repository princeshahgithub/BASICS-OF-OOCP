int dp[1000][1000];
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        const int n=arr.size();
        fill(&dp[0][0], &dp[0][0]+n*1000, 2);
        int ans=0;
      
        // compute DP
       for (int i1=1; i1<n-1; i1++) {
            int f1=arr[i1];
            for (int i2=i1+1; i2<n; i2++) {
                int f2=arr[i2];
                int f0=f2-f1;  // Fibonacci first term
                if (f0>=f1) break; // impossible for tuple (f0, f1, f2)
                int i0=lower_bound(arr.begin(), arr.begin()+i1, f0)-arr.begin();
                if (i0<i1 && f0==arr[i0]) {  // Found
                    dp[i1][i2]=dp[i0][i1]+1;
                }

                ans=max(ans, dp[i1][i2]);  // Track the maximum length
            }
        }

        return ans>2?ans:0;  // sequences of length >= 3
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();