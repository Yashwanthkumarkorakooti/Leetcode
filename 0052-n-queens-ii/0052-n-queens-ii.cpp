class Solution {
public:
    void sloveQueens(int col,int &count, vector<vector<string>>& res, vector<string>&board , vector<int>&leftRow, 
                vector<int> &lowerDiagonal, vector<int> & upperDiagonal, int n){

        if(col == n){
            count++;
            return;
        }

        for(int row=0;row<n;row++){
            if(leftRow[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[n-1+col-row] == 0){
                board[row][col] = 'Q';
                leftRow[row] = 1 ;
                lowerDiagonal[col+row] = 1 ;
                upperDiagonal[n-1+col-row] = 1 ;
                sloveQueens(col+1,count,res,board,leftRow,lowerDiagonal,upperDiagonal,n);
                board[row][col] = '.';
                leftRow[row] = 0 ;
                lowerDiagonal[col+row] = 0 ;
                upperDiagonal[n-1+col-row] = 0 ;
            }
        }
    }
    int totalNQueens(int n) {
        int count = 0 ;
        vector<vector<string>> result ;
        vector<string> board(n,string(n,'.'));
        vector<int> leftrow(n,0);
        vector<int> lowerDiag(2*n-1,0);
        vector<int> upperDiag(2*n-1,0);
        sloveQueens(0,count,result,board,leftrow,lowerDiag,upperDiag,n);
        return count;
    }
};