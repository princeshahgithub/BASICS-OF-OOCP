class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n<=0) return 0;
        int exp=31-countl_zero((unsigned)n);// log2(n)
        return (exp&1)==0 && n==1<<exp;
    }
};