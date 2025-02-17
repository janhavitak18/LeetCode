class Solution {
public:
    void send(vector<vector<int>>& grid, int i, int j, int& ans) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            grid[i][j] == 0)
            return;
        grid[i][j] = 0;
        ans++;
        send(grid, i + 1, j, ans);
        send(grid, i, j + 1, ans);
        send(grid, i - 1, j, ans);
        send(grid, i, j - 1, ans);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int res = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == 1) {
                    int ans = 0;
                    send(grid, i, j, ans);
                    res = max(res, ans);
                }
        return res;
    }
};