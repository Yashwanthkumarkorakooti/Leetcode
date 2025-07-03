class Solution {
public:
    int helperFunction(int start, int end, vector<int>&arr)
    {
        int p2 = 0;
        int p1 = 0;
        for(int i=start; i<=end; i++)
        {
            int temp = p1;
            p1 = max(p1, arr[i] + p2);
            p2 = temp;
        }
        return p1;
    }
    int rob(vector<int>& arr) {
        int n = arr.size();
        if(n == 1)
            return arr[0];
        return max(helperFunction(0, n-2, arr), helperFunction(1, n-1, arr));
    }
};