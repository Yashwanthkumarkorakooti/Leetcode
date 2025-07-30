class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxEle = *max_element(nums.begin(),nums.end());

        int cur = 0 ;
        int maxi = 0 ;

        for(int i=0;i<n;i++){
            if(nums[i] == maxEle){
                cur++ ;
                if(cur > maxi)
                    maxi = cur;
            }
            else
                cur = 0 ;
        }
    return maxi ;
    }
};