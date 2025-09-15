class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (parent[x] != x) parent[x] = find(parent[x], parent);
        return parent[x];
    }
    void unionSet(int a, int b, vector<int>& parent, vector<int>& rank) {
        int pa = find(a, parent), pb = find(b, parent);
        if (pa == pb) return;
        if (rank[pa] < rank[pb]) swap(pa, pb);
        parent[pb] = pa;
        if (rank[pa] == rank[pb]) rank[pa]++;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n), rank(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
        for (auto& e : edges) unionSet(e[0], e[1], parent, rank);
        unordered_set<int> roots;
        for (int i = 0; i < n; i++) roots.insert(find(i, parent));
        return roots.size();
    }
};
