class Solution {
public:
    bool areNumbersAscending(string s) {
        vector<int> numbers;
        int num = 0;
        bool inNumber = false;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0'); 
                inNumber = true;
            } else if (inNumber) {
                numbers.push_back(num); 
                num = 0; 
                inNumber = false;
            }
        }

        if (inNumber) { 
            numbers.push_back(num);
        }
        for(int i = 1; i < numbers.size(); ++i)
            if(numbers[i-1] >= numbers[i]) return false;
        
        return true;

    }
};