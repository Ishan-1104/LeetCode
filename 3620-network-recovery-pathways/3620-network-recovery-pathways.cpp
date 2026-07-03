class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                         long long k) {
        int n = online.size();

        vector<vector<pair<int, int>>> adj(n);

        vector<int> degree(n, 0);

        int maxEdge = 0;

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            degree[v]++;

            maxEdge = max(maxEdge, w);
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (degree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> topo;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for (auto& it : adj[node]) {
                int nxt = it.first;

                degree[nxt]--;

                if (degree[nxt] == 0)
                    q.push(nxt);
            }
        }

        auto check = [&](int mid) {
            const long long INF = 1e18;
            vector<long long> dp(n, INF);

            dp[0] = 0;

            for (int u : topo) {

                if (dp[u] == INF)
                    continue;

                if (u != 0 && u != n - 1 && !online[u])
                    continue;

                for (auto& it : adj[u]) {

                    int v = it.first;
                    int w = it.second;

                    if (w < mid)
                        continue;

                    if (v != n - 1 && !online[v])
                        continue;

                    dp[v] = min(dp[v], dp[u] + w);
                }
            }

            return dp[n - 1] <= k;
        };

        int low = 0;
        int high = maxEdge;

        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};