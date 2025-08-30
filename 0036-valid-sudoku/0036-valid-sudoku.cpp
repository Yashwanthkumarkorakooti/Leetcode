class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char val){
        for(int i=0;i<9;i++){
            if(board[i][col] == val) return false;
            if(board[row][i] == val) return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == val) return false ;
        }
        return true ;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] != '.'){
                    char temp = board[i][j];
                    board[i][j] = '.'; // temporarily remove value
                    if (!isValid(board, i, j, temp)) return false;
                    board[i][j] = temp; // restore value
                }
            }
        }
        return true ;
    }
};