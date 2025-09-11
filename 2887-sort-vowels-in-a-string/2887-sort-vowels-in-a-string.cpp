class Solution {
public:

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    string sortVowels(string s) {
        int n = s.size();
        
        string vowels = "";
        for (char c : s) {
            if (isVowel(c)) {
                vowels += c;
            }
        }

        sort(vowels.begin(), vowels.end());

        int j = 0;
        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                s[i] = vowels[j++];
            }
        }
        
        return s;
    }
};