class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), sum = 0, queryCount = 0;
        vector<int> diffArray(n + 1);

        for (int i = 0; i < n; i++) {
            while (sum + diffArray[i] < nums[i]) {
                queryCount++;
                if (queryCount > queries.size()) return -1;

                int left = queries[queryCount - 1][0], right = queries[queryCount - 1][1], value = queries[queryCount - 1][2];
                if (right >= i) {
                    diffArray[max(left, i)] += value;
                    if (right + 1 < diffArray.size()) {
                        diffArray[right + 1] -= value;
                    }
                }
            }
            sum += diffArray[i];
        }
        return queryCount;
    }
};
