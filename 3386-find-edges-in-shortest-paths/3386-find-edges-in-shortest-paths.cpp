class Solution {
public:
    vector<int> dijkstra(vector<vector<pair<int,int>>> &adj, int src, int n){
        vector<int>dist(n,INT_MAX);
        dist[src] = 0 ;
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq ;
        pq.push({0,src});

        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            int d = x.first;
            int cur = x.second;

            if(d > dist[cur]) continue;

            for(auto& k : adj[cur]){
                int neighbour = k.first;
                int weight = k.second;
                if(dist[cur] + weight < dist[neighbour]){
                    dist[neighbour] = dist[cur] + weight;
                    pq.push({dist[neighbour], neighbour});
                }
            }
        }
        return dist;
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        int E = edges.size();
        vector<vector<pair<int,int>>> adj(n);
        for(auto& edge:edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int> fromSrc = dijkstra(adj,0,n);
        vector<int> fromDest = dijkstra(adj,n-1,n);

        vector<bool> result(E, false);

        for(int i=0;i<E;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            long long distFromSrc = fromSrc[u];
            long long distFromDest = fromDest[v];

             if(distFromSrc + w + distFromDest == fromSrc[n-1]) {
                result[i] = true;
            }

            distFromSrc  = fromSrc[v]; 
            distFromDest = fromDest[u]; 
            if(distFromSrc + w + distFromDest == fromSrc[n-1]) {
                result[i] = true;
            }
        }

        return result;
    }
};