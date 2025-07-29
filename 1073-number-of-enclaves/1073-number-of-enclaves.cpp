class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& visited){
        int m = grid.size();
        int n = grid[0].size();

        visited[i][j] = 1 ;

        if(i>0 && grid[i-1][j] && !visited[i-1][j])
            dfs(i-1,j,grid,visited);
        if(i+1<m && grid[i+1][j] && !visited[i+1][j])
            dfs(i+1,j,grid,visited);
        if(j>0 && grid[i][j-1] && !visited[i][j-1])
            dfs(i,j-1,grid,visited);
        if(j+1<n && grid[i][j+1] && !visited[i][j+1])
            dfs(i,j+1,grid,visited);
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));

        for(int j=0;j<n;j++){
            if(grid[0][j]== 1 && !visited[0][j])
                dfs(0,j,grid,visited);
            if(grid[m-1][j]==1 && !visited[m-1][j])
                dfs(m-1,j,grid,visited);
        }

        for(int i=0;i<m;i++){
            if(grid[i][0]== 1 && !visited[i][0])
                dfs(i,0,grid,visited);
            if(grid[i][n-1]==1 && !visited[i][n-1])
                dfs(i,n-1,grid,visited);
        }

        int count = 0;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j] == 1 && !visited[i][j])
                    count++;
            }
        }
        return count;
    }
};