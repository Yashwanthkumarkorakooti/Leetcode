class Solution {
public:
    bool isPalindrome(int x) {
        long reverse = 0 ;
        int n = x ;
        while(x>0){
            long lastDigit = x % 10 ;
            reverse = reverse*10 + lastDigit ;
            x /= 10 ;
        }
        if (n == reverse){
            return true;
        }else{
            return false;
        }
    }
};