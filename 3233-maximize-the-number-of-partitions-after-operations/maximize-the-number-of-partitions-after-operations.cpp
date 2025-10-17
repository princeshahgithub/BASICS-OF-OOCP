class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.size();
        vector<vector<int>> L(n, vector<int>(3, 0)), R(n, vector<int>(3, 0));

        int num = 0, mask = 0, cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            int bit_mask = 1 << (s[i] - 'a');
            if (!(mask & bit_mask)) {
                cnt++;
                if (cnt <= k)
                    mask |= bit_mask;
                else {
                    num++;
                    mask = bit_mask;
                    cnt = 1;
                }
            }
            L[i + 1][0] = num;
            L[i + 1][1] = mask;
            L[i + 1][2] = cnt;
        }

        num = mask = cnt = 0;
        for (int i = n - 1; i > 0; i--) {
            int bit_mask = 1 << (s[i] - 'a');
            if (!(mask & bit_mask)) {
                cnt++;
                if (cnt <= k)
                    mask |= bit_mask;
                else {
                    num++;
                    mask = bit_mask;
                    cnt = 1;
                }
            }
            R[i - 1][0] = num;
            R[i - 1][1] = mask;
            R[i - 1][2] = cnt;
        }

        int max_val = 0;
        for (int i = 0; i < n; i++) {
            int seg = L[i][0] + R[i][0] + 2;
            int split = L[i][1] | R[i][1];
            int count = __builtin_popcount(split);

            if (L[i][2] == k && R[i][2] == k && count < 26)
                seg += 1;
            else if (min(count + 1, 26) <= k)
                seg -= 1;

            max_val = max(max_val, seg);
        }
        return max_val;
    }
};