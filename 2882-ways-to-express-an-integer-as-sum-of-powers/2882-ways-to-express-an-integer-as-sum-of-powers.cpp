class Solution {
public:
    int M = 1e9+7;
    int t[301][301];

    int solve(int n, int num, int x) {
        if (n == 0) return 1; 
        if (n < 0) return 0;  

        int curPowValue = pow(num, x);
        if (curPowValue > n) return 0; 

        if (t[n][num] != -1) 
            return t[n][num];

        int take = solve(n - curPowValue, num + 1, x) % M;
        int skip = solve(n, num + 1, x) % M;

        return t[n][num] = (take + skip) % M;
    }
    int numberOfWays(int n, int x) {
        memset(t, -1, sizeof(t));
        return solve(n,1,x);
    }
};