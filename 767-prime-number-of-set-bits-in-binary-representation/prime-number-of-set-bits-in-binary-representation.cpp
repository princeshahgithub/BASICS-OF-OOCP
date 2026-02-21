class Solution {
public:
    
    bool isPrime(int n) {
        if(n < 2) return false;
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) return false;
        }
        return true;
    }
    
    int dp[21][21][2];   // 20 bits max
    
    int solveDP(string &bits, int pos, int count, bool tight) {
        if(pos == bits.size()) {
            return isPrime(count);
        }
        
        if(dp[pos][count][tight] != -1)
            return dp[pos][count][tight];
        
        int limit = tight ? bits[pos] - '0' : 1;
        int ans = 0;
        
        for(int bit = 0; bit <= limit; bit++) {
            bool newTight = tight && (bit == limit);
            ans += solveDP(bits, pos + 1,
                           count + bit,
                           newTight);
        }
        
        return dp[pos][count][tight] = ans;
    }
    
    int solve(int n) {
        if(n < 0) return 0;
        
        string bits = "";
        while(n > 0) {
            bits = char('0' + (n % 2)) + bits;
            n /= 2;
        }
        
        // Ensure fixed 20-bit representation (important)
        while(bits.size() < 20)
            bits = "0" + bits;
        
        memset(dp, -1, sizeof(dp));
        return solveDP(bits, 0, 0, 1);
    }
    
    int countPrimeSetBits(int left, int right) {
        return solve(right) - solve(left - 1);
    }
};