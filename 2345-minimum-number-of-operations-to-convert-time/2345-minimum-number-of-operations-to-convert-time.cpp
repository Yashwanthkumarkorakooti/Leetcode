class Solution {
public:
    int convertTime(string current, string correct) {
        int h1 = stoi(current.substr(0,2));
        int m1 = stoi(current.substr(3,2));
        int h2 = stoi(correct.substr(0,2));
        int m2 = stoi(correct.substr(3,2));

        int start = h1 * 60 + m1 ;
        int end = h2 * 60 + m2 ;

        int time = end - start ;
        int steps[4] = {60,15,5,1};
        int ans = 0 ;

        for(auto step : steps){
            ans += time / step;
            time %= step ;
        }

        return ans;
    }
};