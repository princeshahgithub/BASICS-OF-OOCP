class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long> p2;
        vector<int> res;
        int mod = 1e9+7, i = 0;
        while (n) {
            if (n & 1) {
                p2.push_back(1L << i); // store actual power
            }
            n >>= 1;
            i++;
        }
        for (auto &q : queries) {
            long long prod = 1;
            for (int j = q[0]; j <= q[1]; j++) {
                prod = (prod * p2[j]) % mod;
            }
            res.push_back(prod);
        }
        return res;
    }
};