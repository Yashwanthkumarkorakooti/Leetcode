class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int maxVal = 0;
        for (const string& s : strs) {
            bool isDigitOnly = true;
            for (char ch : s) {
                if (!isdigit(ch)) {
                    isDigitOnly = false;
                    break;
                }
            }

            int value;
            if (isDigitOnly) {
                value = stoi(s); // Convert to integer
            } else {
                value = s.length(); // Use length if not all digits
            }

            maxVal = max(maxVal, value);
        }
        return maxVal;
    }
};