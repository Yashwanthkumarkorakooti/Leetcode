class Solution {
public:
    int countDigits(int num) {
         string s = to_string(num);
        int count = 0 ;
        for(auto i : s){
            int n = i - '0';
            if (n!=0 and num % n==0) {
                count+=1;
            }
        }
        return count;
        
        
    }
};