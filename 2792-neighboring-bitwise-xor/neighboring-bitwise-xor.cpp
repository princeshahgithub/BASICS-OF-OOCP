class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        return !accumulate(derived.begin(), derived.end(), 0, [](int a, int b) { return a ^ b; });
    }
};