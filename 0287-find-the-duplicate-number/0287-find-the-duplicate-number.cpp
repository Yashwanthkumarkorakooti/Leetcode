class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // unordered_map <int,int> m;
        // for(int i=0;i<nums.size();i++){
        //     m[nums[i]]++;
        // }
        // for(auto k:m){
        //     if(k.second >= 2){
        //         return k.first;
        //     }
        // }
        // return -1;
        while(nums[0] != nums[nums[0]])
            swap(nums[0], nums[nums[0]]);
        return nums[0];
    }
};