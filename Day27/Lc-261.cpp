class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (parent[x] != x) parent[x] = find(parent[x], parent);
        return parent[x];
    }
    bool unionSet(int a, int b, vector<int>& parent, vector<int>& rank) {
        int pa = find(a, parent), pb = find(b, parent);
        if (pa == pb) return false;
        if (rank[pa] < rank[pb]) swap(pa, pb);
        parent[pb] = pa;
        if (rank[pa] == rank[pb]) rank[pa]++;
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<int> parent(n), rank(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
        for (auto& e : edges) {
            if (!unionSet(e[0], e[1], parent, rank)) return false;
        }
        return true;
    }
};
