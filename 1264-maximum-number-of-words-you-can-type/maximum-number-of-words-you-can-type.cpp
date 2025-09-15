class Solution {
private:
    // This function extract all space separated words from given string.
    vector<string>extractWords(string &text){
        
        int n = text.size();
        vector<string> words;
        string temp = "";
        for(int i = 0; i < n; i++){
            if(text[i] == ' '){
                words.push_back(temp);
                temp = "";
            }
            else
                temp += text[i];
        }
        words.push_back(temp);

        return words;
    }

public:
    int canBeTypedWords(string text, string brokenLetters) {
        
        // If brokenLetters has contain 26 letter then not possible to type any word.
        if(brokenLetters.size() == 26)
            return 0;
        unordered_set<char> brokenKey;
        int count = 0;

        // Store all broken key inside set.
        for(char ch: brokenLetters)
            brokenKey.insert(ch);

        // This function extract all space separated words from this text string.
        vector<string> words = extractWords(text);
        // Loop over every string and check if any character of this string is present in the brokenKey.
        for(string str: words){
            bool flag = true;
            for(int i = 0; i < str.size(); i++){
                if(brokenKey.count(str[i])){
                    flag = false;
                    break;
                }
            }
            if(flag)
                count++;
        }

        return count;
    }
};