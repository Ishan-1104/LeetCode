class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<int> odd1, even1;
        vector<int> odd2, even2;

        for (int x : nums) {
            if (x % 2)
                odd1.push_back(x);
            else
                even1.push_back(x);
        }

        for (int x : target) {
            if (x % 2)
                odd2.push_back(x);
            else
                even2.push_back(x);
        }

        sort(odd1.begin(), odd1.end());
        sort(odd2.begin(), odd2.end());

        sort(even1.begin(), even1.end());
        sort(even2.begin(), even2.end());

        long long ans = 0;

        for (int i = 0; i < odd1.size(); i++) {
            if (odd1[i] < odd2[i])
                ans += odd2[i] - odd1[i];
        }

        for (int i = 0; i < even1.size(); i++) {
            if (even1[i] < even2[i])
                ans += even2[i] - even1[i];
        }

        return ans / 2;
    }
};