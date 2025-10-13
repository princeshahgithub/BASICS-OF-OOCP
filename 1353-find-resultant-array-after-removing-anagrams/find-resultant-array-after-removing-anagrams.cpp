#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> result;
        result.push_back(words[0]);

        for (int i = 1; i < n; i++) {
            unordered_map<char, int> mp;
            for (char ch : words[i - 1])
                mp[ch]++;

            bool mismatch = false;
            for (char ch : words[i]) {
                if (mp.find(ch) != mp.end()) {
                    mp[ch]--;
                    if (mp[ch] == 0) mp.erase(ch);
                } else {
                    mismatch = true;
                    break;
                }
            }

            if (!mp.empty() || mismatch)
                result.push_back(words[i]);
        }

        return result;
    }
};