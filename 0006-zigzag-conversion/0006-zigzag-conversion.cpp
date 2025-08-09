class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string result = "";
        int n = s.size();
        int jumps = 2*(numRows-1);

        for(int i=0;i<numRows;i++){
            for(int j=i;j<n;j+=jumps){
                result += s[j];
                if(i>0 && i< numRows-1 && (j+jumps-2*i) < n){
                    result += s[j+jumps-2*i];
                }
            }
        }
        return result;
    }
};