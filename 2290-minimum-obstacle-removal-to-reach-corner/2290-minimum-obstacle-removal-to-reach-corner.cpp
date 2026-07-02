class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector < vector<int>> dist(m, vector<int>(n, INT_MAX));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        dist[0][0] = 0;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int removed = curr[0];
            int x = curr[1];
            int y = curr[2];

            if (removed > dist[x][y])
                continue;

            if (x == m - 1 && y == n - 1) {
                return removed;
            }

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;
                
                int newRemoved = removed + grid[nx][ny];

                if(newRemoved < dist[nx][ny]){
                    dist[nx][ny] = newRemoved;
                    pq.push({newRemoved , nx , ny});
                }
            }
        }
        return -1;
    }
};