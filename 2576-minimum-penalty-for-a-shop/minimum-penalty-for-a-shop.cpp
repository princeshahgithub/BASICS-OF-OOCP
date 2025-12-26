class Solution {
public:
    int bestClosingTime(string customers) {
        int penalty = 0, n = customers.size();
        for (char c : customers)
            if (c == 'Y') penalty++;

        int minPenalty = penalty, bestHour = 0;

        for (int j = 1; j <= n; j++) {
            if (customers[j - 1] == 'Y') penalty--;
            else penalty++;
            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = j;
            }
        }
        return bestHour;
    }
};