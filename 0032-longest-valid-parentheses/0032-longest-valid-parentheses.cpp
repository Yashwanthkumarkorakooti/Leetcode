class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int left = 0, right = 0, maxLen = 0;

        for (char c : s) {
            if (c == '(') left++;
            else right++;

            if (left == right) {
                maxLen = max(maxLen, 2 * right);
            } else if (right > left) {
                left = right = 0; 
            }
        }

        left = right = 0;

        for(int i=n-1;i>=0;i--){
            if(s[i] == '(') left++;
            else right++;

            if(left == right)
                maxLen = max(maxLen, 2*right);
            else if(left > right)
                left = right = 0 ;
        }

        return maxLen;

        // stack<int>stk;
        // stk.push(-1);
        // int maxLen = 0 ;
        // for(int i=0;i<s.size();i++){
        //     if(s[i] == '('){
        //         stk.push(i);
        //     }else{
        //         stk.pop();
        //         if(stk.empty()){
        //             stk.push(i);
        //         }else{
        //             maxLen = max(maxLen,i-stk.top());
        //         }
        //     }
        // }
        // return max_len;
    }
};