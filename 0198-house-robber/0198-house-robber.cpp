class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int p2 = nums[0] ;
        if(n == 1) return p2 ;
        int p1 = max(nums[0],nums[1]);

        for(int i=2;i<=n-1;i++){
            int pick = nums[i] + p2 ;
            int not_pick = p1 ;
            int cur = max(pick,not_pick);
            p2 = p1 ;
            p1 = cur ;
        }
        return p1 ;
    }
};