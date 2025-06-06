#include <bits/stdc++.h>
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // long n_sum = (n*(n+1))/2;
        // int sum = 0 ;
        // for(int i:nums){
        //     sum+=i;
        // }
        // return n_sum - sum;
        int num = n ;
        for(int i=0;i<n;i++){
            num ^= i^ nums[i];
        }
        return num;
    }
};