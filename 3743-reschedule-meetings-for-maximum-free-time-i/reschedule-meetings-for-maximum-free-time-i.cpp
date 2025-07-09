class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gap(n + 1);

        // Calculate gaps between events
        for (int i = 1; i < n; i++) {
            gap[i] = startTime[i] - endTime[i - 1];
        }
        gap[0] = startTime[0]; // before first event
        gap[n] = eventTime - endTime[n - 1]; // after last event

        // Sliding window of size k + 1
        int i = 0, j = k;
        int maxa = 0, sum = 0;

        // Initial window sum
        for (int w = i; w <= n && w <= j; w++) {
            sum += gap[w];
        }
        maxa = max(maxa, sum);

        // Slide the window
        while (j < n) {
            sum -= gap[i++];
            sum += gap[++j];
            maxa = max(maxa, sum);
        }

        return maxa;
    }
};