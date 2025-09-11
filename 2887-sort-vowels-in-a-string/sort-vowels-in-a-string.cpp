class Solution {
public:
    string sortVowels(string s) {
        std::string vowels = "AEIOUaeiou";
        std::vector<char> vowelList;
        for (char c : s){
            if (vowels.find(c) != std::string::npos){
                vowelList.push_back(c);
            }
        }
        std::sort(vowelList.begin(), vowelList.end());
        std::string res = "";
        int vowelIdx = 0;
        for (char c : s){
            if (vowels.find(c) != std::string::npos){
                res += vowelList[vowelIdx++];
            } else {
                res += c;
            }
        }
        return res;
    }
};