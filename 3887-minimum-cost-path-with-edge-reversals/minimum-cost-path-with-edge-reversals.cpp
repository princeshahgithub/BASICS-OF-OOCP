class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,2*wt});
        }
        vector<int>dist(n,1e9);
        dist[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto it:adj[node]){
                int edgeWt=it.second;
                int adjNode=it.first;

                if(dis+edgeWt<dist[adjNode]){
                    dist[adjNode]=dis+edgeWt;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
         return dist[n-1]==1e9 ? (-1) : (dist[n-1]);
    }
};