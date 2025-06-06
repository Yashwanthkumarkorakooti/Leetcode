class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int Xor = 0 ;
        int n = nums.size();
        for(int i=0;i<n;i++){
            Xor ^= nums[i];
        }
        Xor = Xor^k ;
        int count = 0 ;
        while(Xor){
            count++;
            Xor = (Xor & (Xor-1));
        }
        return count;
    }
};