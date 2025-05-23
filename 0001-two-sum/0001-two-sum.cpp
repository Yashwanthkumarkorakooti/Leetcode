class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> numsWithIndexes ;
        for(int i=0;i<nums.size();i++){
            numsWithIndexes.push_back({nums[i],i});
        }
        int i=0;
        int j = nums.size()-1;
        sort(numsWithIndexes.begin(),numsWithIndexes.end());
        while(i<j){
            int sum = numsWithIndexes[i].first + numsWithIndexes[j].first;
            if (sum == target){
                return {numsWithIndexes[i].second, numsWithIndexes[j].second};
            }
            else if (sum < target){
                i++;
            }
            else{
                j--;
            }
        }
        return {};
    }
};