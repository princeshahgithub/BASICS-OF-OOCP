class Solution {
public:
    // \U0001f522 Chakra Resource Counter (Factorial)
    long long factorial(int num) {
        long long chakra = 1;
        for (int i = 1; i <= num; i++) chakra *= i;
        return chakra;
    }

    // \U0001f300 Shadow Clone Builder
    void generatePalindromes(string& clone, int index, vector<string>& validClones, int k) {
        if (index >= (clone.length() + 1) / 2) {
            if (stoll(clone) % k == 0) validClones.push_back(clone);
            return;
        }

        if (index != 0) {
            clone[index] = '0';
            clone[clone.size() - 1 - index] = '0';
            generatePalindromes(clone, index + 1, validClones, k);
        }

        for (char c = '1'; c <= '9'; c++) {
            clone[index] = c;
            clone[clone.size() - 1 - index] = c;
            generatePalindromes(clone, index + 1, validClones, k);
        }
    }

    // \U0001f4a5 Hidden Leaf’s Main Function
    long long countGoodIntegers(int n, int k) {
        vector<string> validClones;
        string baseClone(n, '0');
        generatePalindromes(baseClone, 0, validClones, k);

        set<string> chakraPatterns;

        // \U0001f9e0 Unique Frequency Fingerprint for each Clone
        for (auto& clone : validClones) {
            vector<int> freq(10, 0);
            for (char c : clone) freq[c - '0']++;
            string pattern;
            for (int f : freq) pattern += (char)('a' + f);
            chakraPatterns.insert(pattern);
        }

        long long basePerms = factorial(n);
        long long total = 0;

        for (auto& pattern : chakraPatterns) {
            long long perms = basePerms;
            for (char f : pattern) perms /= factorial(f - 'a');

            if (pattern[0] != 'a') {
                int zeros = pattern[0] - 'a' - 1;
                long long zeroPerms = factorial(n - 1);
                for (int j = 1; j < pattern.size(); j++) zeroPerms /= factorial(pattern[j] - 'a');
                zeroPerms /= factorial(zeros);
                perms -= zeroPerms;
            }

            total += perms;
        }

        return total;
    }
};