class Solution 
{
public:
    int maxEvents(vector<vector<int>>& events) 
    {
        // Step 1: Sort events by start day
        sort(events.begin(), events.end());

        // Step 2: Min-heap for end days
        priority_queue<int, vector<int>, greater<int>> minHeap; 
        
        int i = 0;
        int count = 0;
        int n = events.size();

        // Step 3: Find the last day to simulate
        int lastDay = 0;
        for (const auto& e : events) 
        {
            lastDay = max(lastDay, e[1]);
        }

        // Step 4: Simulate each day
        for (int day = 1; day <= lastDay; day++) 
        {
            // Step 4.1: Add all events starting today
            while (i < n && events[i][0] == day) 
            {
                minHeap.push(events[i][1]);
                i++;
            }

            // Step 4.2: Remove expired events
            while (!minHeap.empty() && minHeap.top() < day) 
            {
                minHeap.pop();
            }

            // Step 4.3: Attend one event with earliest end
            if (!minHeap.empty()) 
            {
                minHeap.pop();
                count++;
            }

            // Step 5: Early stop
            if (i == n && minHeap.empty())
            {
                break;
            }
        }

        // Step 6: Return result
        return count;
    }
};