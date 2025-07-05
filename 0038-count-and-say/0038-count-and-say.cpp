class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string cur = "1";

        for(int k=2;k<=n;k++){
            string next = "" ;
            int i=0,j=1;
            int len = cur.size();
            
            while(j<len){
                if(cur[i] == cur[j]){
                    j++;
                }else{
                    next.append(to_string(j-i)+cur[i]);
                    i = j ;
                    j++;
                }
            }
            next.append(to_string(j-i)+cur[i]);
            cur = next;
        }
        return cur ;
    }
};