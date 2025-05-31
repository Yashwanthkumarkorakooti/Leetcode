class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> stk ;
        string ans = "";
        for(int i=0;i<n;i++){
            while(k!= 0 && !stk.empty() && stk.top() > num[i]){
                stk.pop();
                k--;
            }
            stk.push(num[i]);
        }
        while(k!=0 && !stk.empty()){
            k--;
            stk.pop();
        }

        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }

        while(ans != "" && ans.back() == '0') ans.pop_back();
        reverse(ans.begin(),ans.end());
        if(ans == "") return "0";
        return ans;
    }
};