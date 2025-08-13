class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i=0;
        int n = intervals.size();

        while(i<n && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }

        int start = INT_MAX ;
        int end = -1 ;
        while(i<n && intervals[i][0] <= newInterval[1]){
            if(start == INT_MAX){
                start = intervals[i][0];
            }
            end = intervals[i][1];
            i++;
        }
        start = min(start,newInterval[0]);
        end = max(end,newInterval[1]);

        ans.push_back({start,end});
        
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};