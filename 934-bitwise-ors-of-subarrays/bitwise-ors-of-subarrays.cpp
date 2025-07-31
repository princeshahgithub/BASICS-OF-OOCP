class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        std::unordered_set<int> seen = {0}, output;
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            std::unordered_set<int> newSubs;
            for (std::unordered_set<int>::const_iterator it = seen.cbegin(); it != seen.cend(); ++it) {
                newSubs.insert(*it | arr[i]);
            }
            newSubs.insert(arr[i]);
            seen = newSubs;
            for (auto &num : seen) output.insert(num);
        }
        return output.size();
    }
};