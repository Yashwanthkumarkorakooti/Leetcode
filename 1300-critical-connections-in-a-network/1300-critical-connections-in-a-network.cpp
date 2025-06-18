class Solution {
public:
    void dfs(int cur, int parent,vector<vector<int>>& adj,vector<int> &visited,vector<int> &disc, 
                vector<int> &low, vector<vector<int>>& bridges, int timer){
        visited[cur] = 1 ;
        disc[cur] = timer;
        low[cur] = timer ;
        timer++;
        for(auto k : adj[cur]){
            if(k != parent){
                if(!visited[k]){
                    dfs(k,cur,adj,visited,disc,low,bridges,timer);
                    low[cur] = min(low[cur], low[k]);
                    if(low[k] > disc[cur]){
                        bridges.push_back({cur,k});
                    }
                }else{
                    low[cur] = min(low[cur], low[k]);
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto k : connections){
            adj[k[0]].push_back(k[1]);
            adj[k[1]].push_back(k[0]);
        }

        vector<int> visited(n,0);
        vector<int> disc(n);
        vector<int> low(n);
        vector<vector<int>> bridges ;
        int timer = 0 ;
        dfs(0,-1,adj,visited,disc,low,bridges,timer);
        return bridges;
    }
};