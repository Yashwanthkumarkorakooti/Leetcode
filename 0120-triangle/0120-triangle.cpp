// class Solution {
// public:
//     int t[201][201];
//     int solve(vector<vector<int>>& triangle, int row, int col){
//         int n = triangle.size();
//         if (row == n-1)
//             return triangle[row][col];

//         if(t[row][col] != INT_MAX)
//             return t[row][col];
        
//         int minPath = triangle[row][col] + 
//                       min(solve(triangle, row + 1, col),
//                           solve(triangle, row + 1, col + 1));

//         return t[row][col] = minPath;
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
       
//         for (int i = 0; i < 201; i++) {
//             for (int j = 0; j < 201; j++) {
//                 t[i][j] = INT_MAX;
//             }
//         }
//         return solve(triangle, 0, 0);
//     }
// };

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> t = triangle.back();  

        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                t[col] = triangle[row][col] + min(t[col], t[col + 1]);
            }
        }

        return t[0];
    }
};