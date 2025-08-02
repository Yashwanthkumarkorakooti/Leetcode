class Solution {
public:
    bool subSetSum(int n, vector<int> &nums, int k){
        vector<int> prev(k + 1, 0);
        prev[0] = 1; 
        
        if (nums[0] <= k) prev[nums[0]] = 1;

        for (int i = 1; i < n; i++) {
            vector<int> cur(k + 1, 0);
            cur[0] = 1; 
            for (int total = 1; total <= k; total++) {
                bool not_pick = prev[total];
                bool pick = false;
                if (nums[i] <= total) {
                    pick = prev[total - nums[i]];
                }
                cur[total] = pick || not_pick;
            }
            prev = cur;
        }
        return prev[k];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum  = 0 ;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(sum %2 != 0) 
            return false ;
        return subSetSum(n,nums,sum/2);
    }
};