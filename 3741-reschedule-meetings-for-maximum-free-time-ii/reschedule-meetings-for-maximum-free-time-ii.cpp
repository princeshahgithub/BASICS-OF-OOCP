class Solution 
{
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) 
    {
        int n = startTime.size();

        // Step 1: Combine start and end times into intervals
        vector<pair<int, int>> intervals(n);
        for (int i = 0; i < n; ++i) 
        {
            intervals[i] = {startTime[i], endTime[i]};
        }

        // Step 2: Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        // Step 3: Calculate free time gaps
        vector<int> gaps;
        gaps.push_back(intervals[0].first); // gap before first meeting
        for (int i = 1; i < n; ++i) 
        {
            gaps.push_back(intervals[i].first - intervals[i - 1].second); // between meetings
        }
        gaps.push_back(eventTime - intervals[n - 1].second); // gap after last meeting

        // Step 4: Precompute max gaps before and after each meeting
        vector<int> maxBefore(n + 2, 0), maxAfter(n + 2, 0);
        for (int i = 1; i <= n; ++i) 
        {
            maxBefore[i] = max(maxBefore[i - 1], gaps[i - 1]);
        }
        
        for (int i = n; i >= 1; --i) 
        {
            maxAfter[i] = max(maxAfter[i + 1], gaps[i]);
        }

        int maxFree = 0;

        // Step 5: Try removing each meeting
        for (int i = 0; i < n; ++i) 
        {
            int duration = intervals[i].second - intervals[i].first;
            int leftGap = gaps[i];
            int rightGap = gaps[i + 1];
            int combinedGap = leftGap + rightGap;

            int bestGap = max(i > 0 ? maxBefore[i] : 0,
                              i < n - 1 ? maxAfter[i + 2] : 0);

            if (duration <= bestGap) 
            {
                maxFree = max(maxFree, combinedGap + duration);
            } 
            else 
            {
                maxFree = max(maxFree, combinedGap);
            }
        }

        // Step 6: Check original max gap without rescheduling
        for (int gap : gaps) 
        {
            maxFree = max(maxFree, gap);
        }

        // Step 7: Return the max free time
        return maxFree;
    }
};