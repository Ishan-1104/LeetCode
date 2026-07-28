class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> val;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                val.push_back(matrix[i][j]);
            }
        }
        sort(val.begin(), val.end());

        return val[k - 1];
    }
};