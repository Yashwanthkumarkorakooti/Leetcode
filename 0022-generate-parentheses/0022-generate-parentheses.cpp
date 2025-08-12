class Solution {
public:
    void solve(vector<string> &result, string & cur,int n, int open, int close){
        if(cur.length() == 2*n){
            result.push_back(cur);
            return;
        }

        if(open < n){
            cur.push_back('(');
            solve(result,cur,n,open+1,close);
            cur.pop_back();
        }
        if(close < open){
            cur.push_back(')');
            solve(result,cur,n,open,close+1);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result ;
        string cur = "";
        int open = 0 , close = 0 ;
        solve(result,cur,n,open,close);
        return result;
    }
};