class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0));
        int ans = 0;
        vector<int> dirs = {0,1,0,-1,0};
        function<int(int,int)> dfs = [&](int i, int j) {
            if (memo[i][j]) return memo[i][j];
            int best = 1;
            for (int d = 0; d < 4; d++) {
                int ni = i + dirs[d], nj = j + dirs[d+1];
                if (ni >= 0 && nj >= 0 && ni < m && nj < n && matrix[ni][nj] > matrix[i][j]) {
                    best = max(best, 1 + dfs(ni, nj));
                }
            }
            return memo[i][j] = best;
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(i, j));
            }
        }
        return ans;
    }
};
