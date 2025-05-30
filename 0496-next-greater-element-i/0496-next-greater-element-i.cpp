class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(),-1);
        unordered_map<int,int> m ;
        stack<int> stk;

        for(int i=0;i<nums2.size();i++){
            while(!stk.empty() && nums2[i] > stk.top()){
                m[stk.top()] = nums2[i];
                stk.pop();
            }
            stk.push(nums2[i]);
        } 

        for(int i=0;i<nums1.size();i++){
            if(m.find(nums1[i]) != m.end()){
                res[i] = m[nums1[i]];
            }
        }
        return res;
    }
};