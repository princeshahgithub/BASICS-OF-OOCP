class Solution {
public:
    int numberOfSubstrings(std::string s) {
        std::vector<int> count(3, 0); // To store counts of 'a', 'b', and 'c'
        int left = 0; // Left pointer of the window
        int result = 0; // To store the result

        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++; // Increment the count of the current character

            // When all three characters are present in the window
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                result += s.length() - i; // All substrings starting at left and ending at i or beyond are valid
                count[s[left] - 'a']--; // Decrement the count of the left character
                left++; // Move the left pointer
            }
        }
        return result; 
    }
};