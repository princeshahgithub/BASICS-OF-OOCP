class Solution {
public:
    void permute(string& s, int ind, vector<string>& ans) {
        int n = s.size();
        if (ind == n) {
            ans.push_back(s);
            return;
        }
        for (int i = ind; i < n; i++) {
            swap(s[i], s[ind]);       // Choose
            permute(s, ind + 1, ans); // Explore
            swap(s[i], s[ind]);       // Backtrack
        }
    }
    bool reorderedPowerOf2(int n) {
        vector<string> ans;
        string str = to_string(n);
        permute(str, 0, ans);
        for (string& perm : ans) {
            if (perm[0] == '0')
                continue; // skip leading zeros
            int num = stoi(perm);
            if (num > 0 && (num & (num - 1)) == 0) {
                return true;
            }
        }
        return false;
    }
};