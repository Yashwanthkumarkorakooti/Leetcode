class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();
        stack<int> stk;
        vector<int> nse(n);
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && arr[stk.top()] >= arr[i])
                stk.pop();
            if(!stk.empty())
                nse[i] = stk.top();
            else
                nse[i] = n ;
            stk.push(i);
        }
        while(!stk.empty()) stk.pop();

        vector<int>pse(n);
        for(int i=0;i<n;i++){
            while(!stk.empty() && arr[stk.top()] > arr[i])
                stk.pop();
            if(!stk.empty())
                pse[i] = stk.top();
            else 
                pse[i] = -1 ;
            stk.push(i);
        }
        while(!stk.empty()) stk.pop();

        vector<int> nge(n);
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && arr[stk.top()] <= arr[i])
                stk.pop();
            if(!stk.empty())
                nge[i] = stk.top();
            else
                nge[i] = n ;
            stk.push(i);
        }
        while(!stk.empty()) stk.pop();

        vector<int>pge(n);
        for(int i=0;i<n;i++){
            while(!stk.empty() && arr[stk.top()] < arr[i])
                stk.pop();
            if(!stk.empty())
                pge[i] = stk.top();
            else 
                pge[i] = -1 ;
            stk.push(i);
        }

        long long sum = 0 ;
        for(int i=0;i<n;i++){
            sum += 1LL* (((i-pge[i])*(nge[i]-i)) - ((i-pse[i])*(nse[i]-i))) * arr[i] ;
        }

        return sum ;
    }
};