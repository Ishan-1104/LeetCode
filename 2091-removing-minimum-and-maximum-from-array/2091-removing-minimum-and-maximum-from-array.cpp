class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mxIdx = max_element(nums.begin() , nums.end()) - nums.begin();
        int mnIdx = min_element(nums.begin() , nums.end()) - nums.begin();

        int n = nums.size();

        if(mnIdx > mxIdx){
            swap(mnIdx , mxIdx);
        }

        int front = mxIdx + 1;
        int back = n - mnIdx;
        int both = (mnIdx+1) + (n-mxIdx);

        return min({front , back , both});

    }
};