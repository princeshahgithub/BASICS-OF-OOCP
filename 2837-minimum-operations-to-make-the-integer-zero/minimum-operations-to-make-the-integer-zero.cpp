class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int ans = 1;
        long long t = num1 - num2;
        while(t>0) {
            if (check(t) == ans) return ans;
            if (check(t) <= ans && t>=ans) return ans;
            ++ans;
            t -= num2;
        }
        return -1;
    }

    int check(long long num) {
        int ans = 0;
        while (num>0) {
            if (num%2) ++ans;
            num/=2;
        }
        return ans;
    }
};