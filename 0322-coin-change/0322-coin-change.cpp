class Solution {
public:
    int helper(vector<int>&arr , int balance, vector<int> &dp){
        if(balance == 0) return 0 ;
        if(balance < 0) return -1 ;
        if(dp[balance] != -2) return dp[balance];
        int mini = INT_MAX ;
        for(int i=0;i<arr.size();i++){
            int count = helper(arr, balance-arr[i],dp);

            if(count != -1)
                mini = min(mini, 1+count);
        }
        dp[balance] = (mini != INT_MAX) ? mini : -1 ;
        return dp[balance];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-2);
        return helper(coins,amount,dp);
    }
};