class Solution {
public:
    int m, n;

    int dfs(int i, int j, vector<vector<int>>& grid) {

        if (i < 0 || j < 0 || i >= m || j >= n)
            return 0;

        if (grid[i][j] == 0)
            return 0;

        grid[i][j] = 0;

        return 1 + dfs(i + 1, j, grid) + dfs(i - 1, j, grid) +
               dfs(i, j + 1, grid) + dfs(i, j - 1, grid);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        int maxArea = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {

                    int area = dfs(i, j, grid);

                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};