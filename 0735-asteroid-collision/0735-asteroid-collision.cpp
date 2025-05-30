class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        stack<int> stk;
        for(int i=0;i<n;i++){
            if(arr[i] > 0) stk.push(arr[i]);
            while(!stk.empty() && stk.top()>0 && stk.top()+ arr[i] < 0)
                stk.pop();
            if(stk.empty() || stk.top() < 0)
                stk.push(arr[i]);
            else if(stk.top()+ arr[i] == 0)
                stk.pop();
        }

        vector<int> ans(stk.size());
        int i = stk.size() - 1 ;
        while(!stk.empty()){
            ans[i] = stk.top();
            stk.pop();
            i--;
        }

        return ans;
    }
};