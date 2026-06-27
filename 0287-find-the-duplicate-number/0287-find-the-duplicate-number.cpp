class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        int ans ;

        for (int x : nums) {
            if (st.count(x))
                ans = x;
            st.insert(x);
        }
        return ans ;
        
    }
};