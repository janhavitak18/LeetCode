class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        vector<vector<bool>> p(n, vector<bool>(m, false));
        vector<vector<bool>> a(n, vector<bool>(m, false));
        vector<vector<int>> res;

        for (int i = 0; i < n; i++) {
            dfs(nums, i, 0, p, INT_MIN);
            dfs(nums, i, m - 1, a, INT_MIN);
        }

        for (int i = 0; i < m; i++) {
            dfs(nums, 0, i, p, INT_MIN);
            dfs(nums, n - 1, i, a, INT_MIN);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (p[i][j] && a[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }

private:
    void dfs(vector<vector<int>>& nums, int r, int c, vector<vector<bool>>& vis,
             int prev) {
        if (r < 0 || r >= nums.size() || c < 0 || c >= nums[0].size() ||
            nums[r][c] < prev)
            return;
        if (vis[r][c])
            return;

        vis[r][c] = true;
        prev = nums[r][c];

        dfs(nums, r + 1, c, vis, prev);
        dfs(nums, r - 1, c, vis, prev);
        dfs(nums, r, c + 1, vis, prev);
        dfs(nums, r, c - 1, vis, prev);
    }
};
