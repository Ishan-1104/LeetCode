class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if (k == 0) {
            return nums1 == nums2 ? 0 : -1;
        }

        long long positive = 0;
        long long negative = 0;

        for (int i = 0; i < nums1.size(); i++) {
            long long diff = nums2[i] - nums1[i];

            if (diff % k != 0)
                return -1;

            if (diff > 0)
                positive += diff;
            else
                negative += -diff;
        }

        if (positive != negative)
            return -1;

        return positive / k;
    }
};