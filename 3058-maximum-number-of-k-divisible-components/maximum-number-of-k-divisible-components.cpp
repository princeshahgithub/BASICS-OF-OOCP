class Solution {
public:
    int ans = 0, K;
    vector<vector<int>> adj, V;

    long dfs(int node, int parent, vector<int>& values) {
        long sum = values[node];
        for(int nxt : adj[node]) {
            if(nxt != parent) sum += dfs(nxt, node, values);
        }
        if(sum % K == 0) ans++;
        return sum % K;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        adj.assign(n, {});
        K = k;

        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1, values);
        return ans;
    }
};