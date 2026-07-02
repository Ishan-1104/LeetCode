class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        // if (k >= m + n - 2)
        //     return m + n - 2;

        vector<vector<vector<bool>>> visited(
            m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));

        queue<vector<int>> q;

        // {x, y, remaining_k, steps}
        q.push({0, 0, k, 0});
        visited[0][0][k] = true;

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        while (!q.empty()) {

            auto curr = q.front();
            q.pop();

            int x = curr[0];
            int y = curr[1];
            int remain = curr[2];
            int steps = curr[3];

            if (x == m - 1 && y == n - 1)
                return steps;

            for (int i = 0; i < 4; i++) {

                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;

                int newRemain = remain - grid[nx][ny];

                if (newRemain < 0)
                    continue;

                if (!visited[nx][ny][newRemain]) {

                    visited[nx][ny][newRemain] = true;
                    q.push({nx, ny, newRemain, steps + 1});
                }
            }
        }

        return -1;
    }
};