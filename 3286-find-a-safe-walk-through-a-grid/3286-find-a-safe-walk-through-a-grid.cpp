class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> best(m, vector<int>(n, -1));

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        priority_queue<vector<int>> pq;

        best[0][0] = health - grid[0][0];
        pq.push({best[0][0], 0, 0});

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int currHealth = curr[0];
            int x = curr[1];
            int y = curr[2];

            if (x == m - 1 && y == n - 1 && currHealth >=1) {
                return true;
            }
            if (currHealth < best[x][y])
                continue;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;

                int newHealth = currHealth - grid[nx][ny];

                if (newHealth > 0 && newHealth > best[nx][ny]) {
                    best[nx][ny] = newHealth;
                    pq.push({newHealth, nx, ny});
                }
            }
        }

        return false;
    }
};