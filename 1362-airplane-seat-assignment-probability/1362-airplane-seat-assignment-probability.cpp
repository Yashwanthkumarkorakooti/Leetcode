class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        // if(n==1)
        //     return 1.0 ;
        
        // double break_cycle = 1.0/n ;
        // double neither_1st_nor_last = (n-2.0)/n;
        // return break_cycle + neither_1st_nor_last * nthPersonGetsNthSeat(n-1);
        return n == 1 ? 1 : 0.5;
    }
};



