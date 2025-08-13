class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans ;
        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i=0;i<n;i++){
            // if(ans.empty() || intervals[i][0] > ans.back()[1]){
            //     ans.push_back(intervals[i]);
            // }
            // else if(intervals[i][0] <= ans.back()[1]){
            //     ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            // }
            if(end >= intervals[i][0]){
                end = max(end,intervals[i][1]);
            }else{
                ans.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};