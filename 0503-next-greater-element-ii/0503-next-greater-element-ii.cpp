class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // int n = nums.size();
        // vector<int>result(n,-1);
        // stack<int> s ;
        // for(int i=0;i< 2*n;i++){
        //      int num = nums[i % n];

        //     while (!s.empty() && nums[s.top()] < num) {
        //         result[s.top()] = num;
        //         s.pop();
        //     }
        //     if (i<n){
        //         s.push(i);
        //     }
        // }
        // return result;
        int n = nums.size();
        vector<int> res(n,-1);
        stack<int> stk;

        for(int i=2*n-1;i>=0;i--){
            while(!stk.empty() && nums[i%n] >= stk.top())
                stk.pop();

            if(i<n && !stk.empty())
                res[i] = stk.top();

            stk.push(nums[i%n]);
        }
        return res;
    }
};