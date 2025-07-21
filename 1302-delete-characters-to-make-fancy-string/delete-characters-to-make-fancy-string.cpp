#include <string>

using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        string result;
        for (char c : s) {
            if (result.size() >= 2 && result.back() == c && result[result.size() - 2] == c) {
                continue;
            }
            result.push_back(c);
        }
        return result;
    }
};