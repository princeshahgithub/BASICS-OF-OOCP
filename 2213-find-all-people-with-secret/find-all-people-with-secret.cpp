class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) parent[b] = a;
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(),
             [](auto &a, auto &b) { return a[2] < b[2]; });

        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        unite(0, firstPerson);

        int m = meetings.size();
        int i = 0;

        while (i < m) {
            int time = meetings[i][2];
            vector<int> people;

            int j = i;
            while (j < m && meetings[j][2] == time) {
                int x = meetings[j][0];
                int y = meetings[j][1];
                unite(x, y);
                people.push_back(x);
                people.push_back(y);
                j++;
            }
            for (int p : people) {
                if (find(p) != find(0)) {
                    parent[p] = p;
                }
            }

            i = j;
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (find(i) == find(0))
                result.push_back(i);
        }

        return result;
    }
};