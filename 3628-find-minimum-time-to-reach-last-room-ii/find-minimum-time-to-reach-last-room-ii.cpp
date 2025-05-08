#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> bestTime(n, vector<int>(m, INT_MAX));
        vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        // Min-heap: [time, i, j, nextMoveTime]
        using T = tuple<int, int, int, int>;
        priority_queue<T, vector<T>, greater<>> pq;
        pq.emplace(0, 0, 0, 0);

        while (!pq.empty()) {
            auto [time, i, j, nextMoveTime] = pq.top(); pq.pop();

            if (time >= bestTime[i][j]) continue;
            bestTime[i][j] = time;

            if (i == n - 1 && j == m - 1) return time;

            for (auto& d : directions) {
                int x = i + d[0], y = j + d[1];
                if (x >= 0 && x < n && y >= 0 && y < m) {
                    int wait = moveTime[x][y];
                    int futureMove = nextMoveTime == 1 ? 2 : 1;
                    int nextTime = wait > time ? wait + futureMove : time + futureMove;

                    if (i == 0 && j == 0 && wait <= time) {
                        nextTime = wait + futureMove;
                    }

                    if (nextTime < bestTime[x][y]) {
                        pq.emplace(nextTime, x, y, futureMove);
                    }
                }
            }
        }

        return -1; // Should never reach
    }
};