class Solution {
public:
    int costc(const string &colors, const vector<int> &neededTime, int i, int n) {
        if (i >= n) return 0;

        int j = i;
        long long sum = 0;
        int mx = 0;
        while (j < n && colors[j] == colors[i]) {
            sum += neededTime[j];
            mx = max(mx, neededTime[j]);
            j++;
        }

        if (j - i == 1) return costc(colors, neededTime, i + 1, n);

        long long removeCost = sum - mx;
        return (int)removeCost + costc(colors, neededTime, j, n);
    }

    int minCost(string colors, vector<int>& neededTime) {
        return costc(colors, neededTime, 0, colors.size());
    }
};