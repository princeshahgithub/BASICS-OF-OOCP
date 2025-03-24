#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int prevEnd = 0;

        for (auto& meeting : meetings) {
            int start = max(meeting[0], prevEnd + 1);
            int length = meeting[1] - start + 1;
            days -= max(length, 0);
            prevEnd = max(prevEnd, meeting[1]);
        }

        return days;
    }
};