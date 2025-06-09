class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n, vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            matrix[i][i] = 0 ;
        }

        for(auto &e:edges){
            int a = e[0];
            int b = e[1];
            int wt = e[2];
            matrix[a][b] = wt;
            matrix[b][a] = wt ;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }

        int minCities = 1e9 ;
        int ans = n-1 ;
        for(int i=n-1;i>=0;i--){
            int count = 0 ;
            for(int j=0;j<n;j++){
                if(matrix[i][j] <= distanceThreshold){
                    count++;
                }
            }

            if(count < minCities){
                minCities = count ;
                ans = i ;
            }
        }
        return ans;
    }
};