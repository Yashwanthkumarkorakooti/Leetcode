class Solution {
public:
    int t[21][21];
    bool solve(int i,int j,string s, string p){
        if(p.length() == j){
            return s.length() == i;
        }

        if(t[i][j] != -1){
            return t[i][j];
        }

        bool first_char_method = false;
        if(s.length() > i && (p[j] == s[i] || p[j] == '.')){
            first_char_method = true;
        }

        if(p[j+1] == '*'){
            bool not_take = solve(i,j+2,s,p);
            bool take = first_char_method && solve(i+1,j,s,p);
            return t[i][j] = not_take || take ;
        }

        return t[i][j] = first_char_method && solve(i+1,j+1,s,p);
    }
    bool isMatch(string s, string p) {
        memset(t,-1,sizeof(t));
        return solve(0,0,s,p);
    }
};