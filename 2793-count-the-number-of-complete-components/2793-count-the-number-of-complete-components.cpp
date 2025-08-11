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
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisjointSet dsu(n);

        // Union all edges
        for (auto &e : edges) {
            dsu.union_size(e[0], e[1]);
        }

        // Count sizes and edge counts
        unordered_map<int,int> compSize;
        unordered_map<int,int> compEdges;
        for (int i = 0; i < n; i++) {
            int root = dsu.find(i);
            compSize[root]++;
        }
        for (auto &e : edges) {
            int root = dsu.find(e[0]);
            compEdges[root]++;
        }

        // Check completeness
        int count = 0;
        for (auto &[root, size] : compSize) {
            int edgesNeeded = size * (size - 1) / 2;
            if (compEdges[root] == edgesNeeded) {
                count++;
            }
        }
        return count;
    }
};
