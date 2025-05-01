class Solution {
    int s;
    vector<int> ts, ws;
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        // O(N log N)
        sort(tasks.begin(), tasks.end());
        // O(M log M)
        sort(workers.begin(), workers.end());

        int n = tasks.size();
        int m = workers.size();
        int left = 0;
        int right = min(n, m);
        int answer = 0;
        // O(log N * (M+N) * log M)
        while (left <= right) {
            // expected number of tasks to be completed.
            int mid = (left + right)/2;

            // (M * log M)
            multiset<int> workersSet(workers.end() - mid, workers.end());
            int pillCountRemaining = pills;
            // O(N * log M)
            for (int i = mid-1; i>=0; --i) {
                auto it = prev(workersSet.end());
                if (*it < tasks[i]) {
                    if (pillCountRemaining == 0) break;
                    it = workersSet.lower_bound(tasks[i] - strength);
                    if (it == workersSet.end()) break;
                    pillCountRemaining--;
                }
                workersSet.erase(it);
            }

            if (workersSet.empty()) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return answer;
    }
};