class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> map ;
        map['I'] = 1 ;
        map['V'] = 5 ;
        map['X'] = 10 ;
        map['L'] = 50 ;
        map['C'] = 100 ;
        map['D'] = 500 ;
        map['M'] = 1000 ;
        
        int n = s.size();

        int ans = 0 ;
        int prev = map[s[n-1]];
        ans += prev ;

        for(int i=n-2;i>=0;i--){
            int cur = map[s[i]];
            if(cur >= prev){
                ans += cur ;
            }else{
                ans -= cur ;
            }
            prev = cur ;
        }

        return ans ;
    }
};