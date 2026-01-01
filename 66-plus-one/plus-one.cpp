class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int sum = 0;
        int carry = 0;
        
        // Traverse from the last digit to the first
        for(int i = n - 1; i >= 0; i--) {
            // Add 1 only if it is the last digit, otherwise just add the carry
            sum = digits[i] + (i == n - 1 ? 1 : 0) + carry;
            
            // If no carry is generated, update and return
            if (sum <= 9) {
                digits[i] = sum;
                return digits;
            }
            
            // If carry is generated (sum is 10)
            digits[i] = sum % 10; // This will set it to 0
            carry = sum / 10;     // This will be 1
        }
        
        // If the loop completes and carry is still non-zero (e.g., 99 -> 100)
        if (carry != 0) {
            digits.insert(digits.begin(), carry);
        }
        
        return digits;
    }
};