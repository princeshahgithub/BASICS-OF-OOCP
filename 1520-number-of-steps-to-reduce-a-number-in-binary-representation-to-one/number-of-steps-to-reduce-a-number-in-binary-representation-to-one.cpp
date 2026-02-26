class Solution {
public:
    int numSteps(string s) {
           
        int steps = 0;
        int carry = 0;

        // Start from rightmost bit and go left
        for (int i = s.length() - 1; i > 0; i--) {
            int bit = s[i] - '0';

            if (bit + carry == 1) {
                // Odd number
                steps += 2;   // add 1 + divide by 2
                carry = 1;    // carry generated
            } else {
                // Even number
                steps += 1;   // just divide by 2
            }
        }

        // If carry still remains, add one more step
        return steps + carry; 

    }
};