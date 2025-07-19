class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long result = 0;
        for (int i = 0; i < nums.size(); i++) {
            auto low = lower_bound(nums.begin(), nums.begin() + i, lower - nums[i]);
            auto up = upper_bound(nums.begin(), nums.begin() + i, upper - nums[i]);
            result += distance(low, up);
        }
        return result;
    }
};