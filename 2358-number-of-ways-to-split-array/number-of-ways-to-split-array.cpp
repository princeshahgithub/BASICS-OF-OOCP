class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int N = nums.size();
        vector<long long> Prefix(N + 1, 0);
        for (int i = 0; i < N; i++) {
            Prefix[i + 1] = Prefix[i] + nums[i];
        }
        int ANS = 0;
        for (int i = 1; i < N; i++) {
            if (Prefix[i] >= Prefix[N] - Prefix[i]) {
                ANS++;
            }
        }
        return ANS;
    }
};