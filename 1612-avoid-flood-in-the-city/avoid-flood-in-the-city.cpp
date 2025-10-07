class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, int> lastRain;
        set<int> dryDays;
        int n = rains.size();
        vector<int> ans(n, 1);

        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                dryDays.insert(i);
            } else {
                ans[i] = -1;
                int lake = rains[i];
                if (lastRain.count(lake)) {
                    auto it = dryDays.lower_bound(lastRain[lake]);
                    if (it == dryDays.end()) return {};
                    ans[*it] = lake;
                    dryDays.erase(it);
                }
                lastRain[lake] = i;
            }
        }
        return ans;
    }
};