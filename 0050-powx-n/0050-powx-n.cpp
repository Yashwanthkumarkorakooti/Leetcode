class Solution {
public:
    double myPow(double x, int n) {
        if(n<0) return 1/x*myPow(1/x, (n+1)*-1); 
        if(n==0) return 1;
        double ans=myPow(x, n/2);
        ans*=ans;
        if(n%2!=0) ans*=x;
        return ans;
    }
};