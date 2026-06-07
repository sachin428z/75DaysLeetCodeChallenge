class DisjointSet {
public:
    /* To store the ranks, parents and 
    sizes of different set of vertices */
    vector<int> rank, parent, size;

    // Constructor
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    // Function to find ultimate parent
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    
    // Function to implement union by rank
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    
    // Function to implement union by size
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class DSU {
public:
    unordered_map<int, int> parent;

    // Function to find the ultimate parent of node x
    int find(int x) {
        // If x is not present, make it its own parent
        if (parent.find(x) == parent.end())
            parent[x] = x;

        // Path compression to optimize future finds
        if (x != parent[x])
            parent[x] = find(parent[x]);

        return parent[x];
    }

    // Function to connect two nodes
    void unite(int x, int y) {
        // Set parent of x's root to y's root
        parent[find(x)] = find(y);
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
      int n=stones.size();
      int maxRow=0;
      int maxCol=0;
      for(auto it: stones) {
        maxRow=max(maxRow,it[0]);
        maxCol=max(maxCol,it[1]);

      }
      DisjointSet ds(maxRow+maxCol+1);
      unordered_map<int,int> stoneNodes;
      for(auto it:stones) {
        int nodeRow=it[0];
        int nodeCol=it[1]+maxRow+1;
        ds.unionBySize(nodeRow,nodeCol);
        stoneNodes[nodeRow]=1;
        stoneNodes[nodeCol]=1;

      }
      int cnt=0;
      for(auto it:stoneNodes) {
        if(ds.findUPar(it.first)==it.first) {
            cnt++;

        }
      }
      return n-cnt;
    }
};