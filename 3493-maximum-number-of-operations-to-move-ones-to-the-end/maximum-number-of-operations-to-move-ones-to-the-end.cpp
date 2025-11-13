class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int cnt1 = (s[0] == '1') ? 1 : 0;
        int total = 0;
        for (int i = 1; i < n; i++){
            if (s[i] == '1'){
                cnt1++;
            }
            if (s[i] == '0' && s[i - 1] == '1'){
                total += cnt1;
            }
        }
        return total;
    }
};