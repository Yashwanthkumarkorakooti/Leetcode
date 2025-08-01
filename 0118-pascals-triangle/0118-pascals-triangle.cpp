class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>> res ;
        for(int i=0;i<n;i++){
            vector<int>a(i+1);
            res.push_back(a);
            for(int j=0;j<=i;j++){
                if(j==0 || j==i){
                    res[i][j] = 1;
                }
                else{
                    res[i][j] = res[i-1][j]+res[i-1][j-1];
                }
            }
        }
        return res;
    }
};