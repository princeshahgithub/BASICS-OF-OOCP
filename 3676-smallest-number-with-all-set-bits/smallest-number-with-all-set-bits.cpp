class Solution {
public:
    int smallestNumber(int n) {
        long long x = 1;
        while (x < n) {
            x = (x << 1) | 1; // keep setting all bits
        }
        return x;
    }
};