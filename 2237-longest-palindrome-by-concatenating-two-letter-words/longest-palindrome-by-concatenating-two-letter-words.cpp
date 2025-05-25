class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int count[26][26] = {};
        int length = 0;

        for (const string& word : words) {
            int a = word[0] - 'a';
            int b = word[1] - 'a';

            if (count[b][a] > 0) {
                // Found reverse word
                length += 4;
                count[b][a]--;
            } else {
                count[a][b]++;
            }
        }

        // Check for one central self-palindromic word
        for (int i = 0; i < 26; ++i) {
            if (count[i][i] > 0) {
                length += 2;
                break;
            }
        }

        return length;
    }
};
