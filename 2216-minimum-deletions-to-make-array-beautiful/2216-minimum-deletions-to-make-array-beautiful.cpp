class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < nums.size() - 1; ) {
            if (i % 2 == 0 && nums[i] == nums[i + 1]) {
                nums.erase(nums.begin() + i);
                ans++;
            } else {
                i++;
            }
        }

        if (nums.size() % 2 == 1)
            ans++;

        return ans;
    }
};