class Solution {
public:
    bool dfs(int start,vector<vector<int>>& graph,vector<int>&visited,vector<int>&path,
    vector<int>&ans){
        visited[start] = 1 ;
        path[start] = 1 ;

        for(auto k: graph[start]){
            if(!visited[k]){
                if(dfs(k,graph,visited,path,ans))
                    return true;
            }else if (path[k]){
                return true;
            }
        }
        path[start] = 0 ;
        ans.push_back(start);
        return false;

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<int>visited(n,0);
        vector<int>path(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i])
                dfs(i,graph,visited,path,ans);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};