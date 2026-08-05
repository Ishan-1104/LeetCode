class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        if (q.empty() || q.size() == n * n)
            return -1;

        vector<pair<int, int>>
            dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int distance = -1;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [x, y] = q.front();
                q.pop();

                for (auto [dx, dy] : dir) {
                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                        grid[nx][ny] == 0) {
                        grid[nx][ny] = 1;

                        q.push({nx, ny});
                    }
                }
            }

            distance++;
        }
        return distance;
    }
};