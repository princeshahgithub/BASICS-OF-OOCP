class Solution {
public:
    vector<int> parent, size;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;

    int findParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }

    void Union(int u, int v) {
        int up = findParent(u);
        int vp = findParent(v);

        if (up == vp) return;

        if (size[up] > size[vp]) {
            size[up] += size[vp];
            parent[vp] = up;
            while (!mp[vp].empty()) {
                mp[up].push(mp[vp].top());
                mp[vp].pop();
            }
        } else {
            size[vp] += size[up];
            parent[up] = vp;
            while (!mp[up].empty()) {
                mp[vp].push(mp[up].top());
                mp[up].pop();
            }
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> ans;
        parent.resize(c);
        size.resize(c, 1);
        vector<int> offline(c, 0);

        for (int i = 0; i < c; i++) {
            parent[i] = i;
            mp[i].push(i);
        }

        for (auto& it : connections) {
            int u = it[0] - 1, v = it[1] - 1;
            Union(u, v);
        }

        for (auto& it : queries) {
            int type = it[0];
            int node = it[1] - 1;

            if (type == 1) {
                if (offline[node] == 0) {
                    ans.push_back(node + 1);
                    continue;
                }
                int par = findParent(node);
                while (!mp[par].empty() && offline[mp[par].top()]) {
                    mp[par].pop();
                }

                if (mp[par].empty()) ans.push_back(-1);
                else ans.push_back(mp[par].top() + 1);
            } else {
                offline[node] = 1;
            }
        }

        return ans;
    }
};