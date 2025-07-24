class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int aheadBuy = 0 ;
        int aheadNotBuy = 0 ;

        for(int i=n-1;i>=0;i--){
            int curNotBuy = max(prices[i]+aheadBuy, aheadNotBuy);
            int curBuy = max(-prices[i]+aheadNotBuy, aheadBuy);

            aheadBuy = curBuy;
            aheadNotBuy = curNotBuy ;
        }

        return aheadBuy;
    }
};