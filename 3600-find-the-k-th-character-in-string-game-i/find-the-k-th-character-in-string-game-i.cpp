class Solution {
public:
char kthCharacter(int k) {
    string word = "a";
    while (word.size() < k) {
        string new_part;
        for (char c : word) {
            if (c == 'z') {
                new_part += 'a';
            } else {
                new_part += c + 1;
            }
        }
        word += new_part;
    }
    return word[k - 1];
}
};