class DisjointSet{
    public:
    vector<int> parent;
    DisjointSet(int n)
    {
        parent.resize(n+1, -1);
    }
    int find(int node){
        if(parent[node] < 0) return node;
        return parent[node] = find(parent[node]);
    }
    void union_size(int a, int b)
    {
        int parent_a = find(a);
        int parent_b = find(b);
        
        if(parent_a != parent_b)
        {
            if(parent[parent_a] < parent[parent_b])
            {
                int temp = parent[parent_b];
                parent[parent_b] = parent_a;
                parent[parent_a] += temp;
            }
            else
            {
                int temp = parent[parent_a];
                parent[parent_a] = parent_b;
                parent[parent_b] += temp;
            }
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DisjointSet disjoint_set(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    disjoint_set.union_size(i,j);
                }
            }
        }

        int ans = 0 ;
        for(int i=0;i<n;i++){
            if(disjoint_set.parent[i] < 0) ans++;
        }
        return n-ans;
    }
};