class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> height(n,0);
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]) height[j]++;
                else height[j] = 0;
            }
            vector<int> sum(n);
            stack<int> st;
            for(int j=0;j<n;j++){
                while(!st.empty() && height[st.top()]>=height[j]) st.pop();
                if(!st.empty()){
                    int p = st.top();
                    sum[j] = sum[p] + height[j] *(j-p);
                }else{
                    sum[j] = height[j] *(j+1);
                }
                st.push(j);
                ans += sum[j];
            }
        } 
        return ans;
    }
};

// class Solution {
// public:
//     int Array(vector<int>& vec){
//         int cons = 0 ;
//         int subCount = 0 ;

//         for(int & val : vec){
//             if(val == 0) cons=0;
//             else cons++;

//             subCount += cons ;
//         }
//         return subCount;
//     }
//     int numSubmat(vector<vector<int>>& mat) {
//         int m = mat.size();
//         int n = mat[0].size();
//         int result = 0 ;

//         for(int startRow=0;startRow<m;startRow++){
//             vector<int>vec(n,1);
//             for(int endRow=startRow;endRow<m;endRow++){

//                 for(int col=0;col<n;col++){
//                     vec[col] = vec[col] & mat[endRow][col];
//                 }

//                 result += Array(vec);
//             }
//         }
//         return result;
//     }
// };
