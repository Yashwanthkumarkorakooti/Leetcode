class Solution {
public:
    // bool helper(string s, int idx, int count){
    //     if(count < 0) return false ;
    //     if(idx == s.size()) return count == 0 ;
    //     if(s[idx] == '(')
    //         return helper(s,idx+1,count+1);
    //     if(s[idx] == ')')
    //         return helper(s,idx+1,count-1);
        
    //     return helper(s,idx+1,count+1) || helper(s,idx+1,count) || helper(s,idx+1,count-1) ;
    // }
    bool checkValidString(string s) {
        // return helper(s,0,0);
        int low = 0, high = 0;
        for (char c : s) {
            if (c == '(') {
                low++; high++;
            } else if (c == ')') {
                low--; high--;
            } else { // c == '*'
                low--; high++;
            }
            if (high < 0) return false;
            if (low < 0) low = 0;
        }
        return low == 0;
    }
};