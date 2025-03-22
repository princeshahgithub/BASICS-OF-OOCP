class Solution {
public:
    void bfs(int node,vector<vector<int>> &adj,vector<int> &comp,vector<bool> &vis){
        queue<int> q;
        q.push(node);
        vis[node]=true;

        while(!q.empty()){
            int n=q.front();
            q.pop();
            comp.push_back(n);
            for(auto it:adj[n]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=true;
                }
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){

            if(!vis[i]){
                vector<int> comp;
                bfs(i,adj,comp,vis);
                bool iscomp=true;
                for(auto it: comp){
                    if(adj[it].size()!=comp.size()-1){
                        iscomp=false;
                        break;
                    }
                }
                if(iscomp)ans++;
            }
        }
        return ans;
    }
};