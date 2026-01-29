#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target,
 vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long dist[26][26];
        const long long INF = 1e14;

        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                dist[i][j] = (i == j) ? 0 : INF;
            }
        }

        for (size_t i = 0; i < original.size(); ++i) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                if (dist[i][k] == INF) continue;
                for (int j = 0; j < 26; ++j) {
                    if (dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        long long totalCost = 0;
        int n = source.length();

        for (int i = 0; i < n; ++i) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if (u == v) continue;
            if (dist[u][v] == INF) return -1;
            totalCost += dist[u][v];
        }

        return totalCost;
    }
};