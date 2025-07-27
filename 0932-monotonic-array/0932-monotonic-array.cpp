class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int positive = 0 ;
        int negative = 0 ;

        int n = nums.size() ;
        for (int i=0 ; i < n-1 ;i++){
            int diff = nums[i+1] - nums[i] ;
            if (diff > 0) {
                positive ++ ;
            }
            else if (diff < 0) {
                negative ++ ;
            }
        }

        if (negative > 0 && positive > 0) {
            return false ;
        }
        else{
            return true ;
        }      
    }
};