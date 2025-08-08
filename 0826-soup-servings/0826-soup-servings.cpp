class Solution {
public:
    double calc(int a, int b, vector<vector<double>> &dp){
        if(a <= 0 && b <= 0) return 0.5;
        if(a <= 0) return 1.0 ;
        if(b <=  0) return 0 ;

        if(dp[a][b] != -1) return dp[a][b];
        double ans  = 0 ;
        ans += 0.25*calc(a-4,b,dp);
        ans += 0.25*calc(a-3,b-1,dp);
        ans += 0.25*calc(a-2,b-2,dp);
        ans += 0.25*calc(a-1,b-3,dp);
        dp[a][b] = ans ;
        return ans;
    }
    double soupServings(int n) {
        if(n > 5000) return 1.0 ;
        n = ceil(n/25.0);
        vector<vector<double>> dp(n+1, vector<double>(n+1,-1));
        return calc(n,n,dp);
    }
};