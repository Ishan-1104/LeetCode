class Solution {
public:
    int nodes = 0;
    int degreeSum = 0;

    void dfs(int u, vector<vector<int>>& lst, vector<int>& vis) {
        vis[u] = 1;
        nodes++;
        degreeSum += lst[u].size();

        for (int v : lst[u]) {
            if (!vis[v])
                dfs(v, lst, vis);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> lst(n);

        for (auto& e : edges) {
            lst[e[0]].push_back(e[1]);
            lst[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i])
                continue;

            nodes = 0;
            degreeSum = 0;

            dfs(i, lst, vis);

            int edgecount = degreeSum / 2;
            if (edgecount == nodes * (nodes - 1) / 2)
                ans++;
        }
        return ans;
    }
};