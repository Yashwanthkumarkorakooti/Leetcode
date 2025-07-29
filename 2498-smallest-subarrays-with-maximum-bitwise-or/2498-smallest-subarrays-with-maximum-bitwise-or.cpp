class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(),nums.end());
        int bits = maxVal == 0 ? 0 : 1+log2(maxVal);

        vector<int> nearest_setBit(bits,n);
        vector<int> ans(n);

        for(int i=n-1;i>=0;i--){
            int nearest = i ;
            for(int j=0;j<bits;j++){
                if(nums[i] & (1<<j)){
                    nearest_setBit[j] = i ;
                }else if(nearest_setBit[j] != n){
                    nearest = max(nearest, nearest_setBit[j]);
                }
            }
            ans[i] = nearest-i+1;
        }
        return ans;
    }
};