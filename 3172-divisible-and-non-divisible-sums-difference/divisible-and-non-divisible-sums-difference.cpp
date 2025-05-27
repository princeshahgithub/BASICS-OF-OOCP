class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum = n * (n + 1) / 2;     // Total sum from 1 to n
        int div = n / m;               // Count of divisible numbers
        int dm = m * div * (div + 1) / 2; // Sum of divisible numbers

        return sum - 2 * dm;
    }
};