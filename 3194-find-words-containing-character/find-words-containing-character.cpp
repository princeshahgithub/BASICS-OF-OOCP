// for_each version
class Solution {
public:
    static vector<int> findWordsContaining(vector<string>& words, char x) {
        const int n=words.size();
        vector<int> ans;
        for_each(words.begin(), words.end(), [&](auto& w) mutable{
            if (w.find(x)!=-1) ans.push_back(&w-&words[0]);
        });
        return ans;
    }
};