#include<bits/stdc++.h>
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // unordered_map <int,int> m;
        // for(int i=0;i<nums.size();i++){
        //     m[nums[i]]++;
        // }
        // for(auto k:m){
        //     if(k.second == 1){
        //         return k.first;
        //     }
        // }
        // return -1;
        int n = nums.size();
        int result = 0 ;
        for(int i=0;i<n;i++){
            result = result ^ nums[i];
        }
        return result;
    }
};