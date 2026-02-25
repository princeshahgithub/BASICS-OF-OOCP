class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {

        vector<vector<int>> lst(15);

        // fill buckets
        for(int num : arr) {
            int bits = __builtin_popcount(num);
            lst[bits].push_back(num);
        }

        vector<int> ans;

        // merge buckets
        for(auto &bucket : lst) {
            sort(bucket.begin(), bucket.end());
            for(int num : bucket)
                ans.push_back(num);
        }

        return ans;
    }
};