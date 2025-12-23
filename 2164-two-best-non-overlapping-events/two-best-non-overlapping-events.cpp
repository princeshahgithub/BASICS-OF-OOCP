class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();

        // sort by end time
        sort(events.begin(), events.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        vector<int> endT(n), best(n);

        for (int i = 0; i < n; i++) {
            endT[i] = events[i][1];
            best[i] = events[i][2];
            if (i > 0) best[i] = max(best[i], best[i - 1]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int st = events[i][0];
            int val = events[i][2];

            // binary search: last event ending before st
            int idx = lower_bound(endT.begin(), endT.end(), st) - endT.begin() - 1;

            if (idx >= 0) {
                ans = max(ans, val + best[idx]);
            }

            ans = max(ans, val); // single event case
        }

        return ans;
    }
};