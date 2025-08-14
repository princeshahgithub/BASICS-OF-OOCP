class Solution {
    vector<string> sameDigitNumbers = {"999", "888", "777", "666", "555", "444", "333", "222", "111", "000"};

    // Check whether the 'num' string contains the 'sameDigitNumber' string or not.
    bool contains(string sameDigitNumber, string num) {
        for (int index = 0; index <= num.size() - 3; ++index) {
            if (num[index] == sameDigitNumber[0] and 
                num[index + 1] == sameDigitNumber[1] and 
                num[index + 2] == sameDigitNumber[2]) {
                return true;
            }
        }
        return false;
    }

public:
    string largestGoodInteger(string num) {
        // Iterate on all 'sameDigitNumbers' and check if the string 'num' contains it.
        for (auto& sameDigitNumber: sameDigitNumbers) {
            if (contains(sameDigitNumber, num)) {
                // Return the current 'sameDigitNumbers'.
                return sameDigitNumber;
            }
        }
        // No 3 consecutive same digits are present in the string 'num'.
        return "";
    }
};