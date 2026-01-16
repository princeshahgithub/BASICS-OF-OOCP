class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        // 1. Add implicit boundary fences (1 and m/n)
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        // 2. Sort to easily calculate gaps
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        // 3. Store all possible horizontal gaps in a HashSet
        unordered_set<int> hGaps;
        for(int i = 0; i < hFences.size(); i++) {
            for(int j = i + 1; j < hFences.size(); j++) {
                hGaps.insert(hFences[j] - hFences[i]);
            }
        }

        // 4. Check all possible vertical gaps against the HashSet
        long long maxSide = -1;
        for(int i = 0; i < vFences.size(); i++) {
            for(int j = i + 1; j < vFences.size(); j++) {
                int currentGap = vFences[j] - vFences[i];
                if(hGaps.count(currentGap)) {
                    maxSide = max(maxSide, (long long)currentGap);
                }
            }
        }

        if(maxSide == -1) return -1;

        // 5. Return area modulo 10^9 + 7
        long long MOD = 1e9 + 7;
        return (maxSide * maxSide) % MOD;
    }
};