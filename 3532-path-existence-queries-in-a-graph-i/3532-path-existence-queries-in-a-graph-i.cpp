class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> ans;
        int component = 0;
        vector<int> val;
        val.push_back(0);

        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] - nums[i-1] > maxDiff)
                component++;
            val.push_back(component);
        }

        for(auto &q : queries){
            ans.push_back(val[q[0]] == val[q[1]]);
        }

        return ans;
    }
};