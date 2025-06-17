class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int mini = INT_MAX ;

        for(auto k : nums){
            if(abs(k) < abs(mini)){
                mini = k ;
            }

            if(abs(k) == abs(mini)){
                mini = max(k,mini);
            }
        }
        return mini;
    }
};