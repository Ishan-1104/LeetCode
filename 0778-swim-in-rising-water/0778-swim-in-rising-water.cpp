class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> time(n, vector<int>(n, INT_MAX));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        time[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int currtime = curr[0];
            int x = curr[1];
            int y = curr[2];

            if (x == n - 1 && y == n - 1)
                return currtime;

            if (currtime > time[x][y])
                continue;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;

                int newtime = max(currtime, grid[nx][ny]);

                if (newtime < time[nx][ny]) {
                    time[nx][ny] = newtime;
                    pq.push({newtime, nx, ny});
                }
            }
        }
        return -1;
    }
};