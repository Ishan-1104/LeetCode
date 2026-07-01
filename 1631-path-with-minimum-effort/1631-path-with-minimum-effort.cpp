class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> efforts(m, vector<int>(n, INT_MAX));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;

        efforts[0][0] = 0;
        pq.push({0, 0, 0});

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int curreffort = curr[0];
            int x = curr[1];
            int y = curr[2];

            if (x == m - 1 && y == n - 1)
                return curreffort;

            if(curreffort > efforts[x][y])
                continue;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx < 0 || ny < 0 || nx >=m || ny>=n)
                    continue;
                
                int newEffort = max(curreffort , abs(heights[nx][ny] - heights[x][y]));

                if(newEffort < efforts[nx][ny]){
                    efforts[nx][ny] = newEffort;
                    pq.push({newEffort, nx, ny});
                }
            }
        }
        return 0;
    }
};