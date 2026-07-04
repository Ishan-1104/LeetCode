class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n + 1);
        vector<bool>visisted(n+1 , false);
        queue<int>q;
        int ans = INT_MAX;

        for(auto& r : roads){
            int u = r[0];
            int v = r[1];
            int w = r[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        q.push(1);
        visisted[1] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(auto&[v,w] : adj[curr]){

                if (!visisted[v]) {
                    visisted[v] = true;
                    q.push(v);
                }

                ans = min(ans,w);
            }
        }
        return ans;
    }
};