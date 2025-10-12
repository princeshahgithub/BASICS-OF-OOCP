#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

class Solution {
public:
    vector<long long> nums;
    int n;
    unordered_map<long long, long long> memo;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    long long modInverse(long long a) {
        return modPow(a, MOD - 2);
    }

    long long nCr(int n, int r) {
        if (r > n) return 0;
        long long res = 1;
        for (int i = 0; i < r; ++i)
            res = res * (n - i) % MOD * modInverse(i + 1) % MOD;
        return res;
    }

    long long encodeKey(int remaining, int odd_needed, int index, long long carry) {
        return ((long long)remaining << 48) ^ ((long long)odd_needed << 32) ^ ((long long)index << 16) ^ carry;
    }

    long long dfs(int remaining, int odd_needed, int index, long long carry) {
        if (remaining < 0 || odd_needed < 0 || remaining + __builtin_popcountll(carry) < odd_needed)
            return 0;
        if (remaining == 0)
            return (__builtin_popcountll(carry) == odd_needed) ? 1 : 0;
        if (index >= n)
            return 0;

        long long key = encodeKey(remaining, odd_needed, index, carry);
        if (memo.count(key))
            return memo[key];

        long long ans = 0;
        for (int take = 0; take <= remaining; ++take) {
            long long ways = nCr(remaining, take) * modPow(nums[index], take) % MOD;
            long long new_carry = carry + take;
            ans += ways * dfs(remaining - take, odd_needed - (new_carry % 2), index + 1, new_carry / 2) % MOD;
            ans %= MOD;
        }

        return memo[key] = ans;
    }

    int magicalSum(int m, int k, vector<int>& numbers) {
        nums.assign(numbers.begin(), numbers.end());
        n = nums.size();
        memo.clear();
        return dfs(m, k, 0, 0);
    }
};