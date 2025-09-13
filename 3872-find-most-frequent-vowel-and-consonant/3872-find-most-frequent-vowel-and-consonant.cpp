class Solution {
public:
    int maxFreqSum(string s) {
        int freq[26] , maxVowel = 0 , maxCons = 0 ;

        for(auto c : s){
            int i = c - 'a';
            freq[i]++;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                maxVowel = max(maxVowel , freq[i]);
            }else{
                maxCons = max(maxCons, freq[i]);
            }
        }

        return maxVowel + maxCons;
    }
};