class Solution {
public:
    const int mod = 1e9 + 7;
    int numOfWays(int n) {
        vector<long long int> a(n,6),b(n,6);
        int tot = 0;
        for(int i=1;i<n;i++){
            a[i] = (2*a[i-1] + 2*b[i-1]) % mod;
            b[i] = (2*a[i-1] + 3*b[i-1]) % mod;
        }
        return (a[n-1] + b[n-1]) % mod;
    }
};