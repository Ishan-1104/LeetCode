class Solution {
public:

    long long atMost(vector<int>& nums, int k) {

        unordered_map<int,int> freq;

        int left = 0;
        long long cnt = 0;

        for(int right = 0; right < nums.size(); right++) {

            freq[nums[right]]++;

            while(freq.size() > k) {

                freq[nums[left]]--;

                if(freq[nums[left]] == 0)
                    freq.erase(nums[left]);

                left++;
            }

            cnt += (right - left + 1);
        }

        return cnt;
    }

    int medianOfUniquenessArray(vector<int>& nums) {

        int n = nums.size();

        long long total = 1LL * n * (n + 1) / 2;

        long long need = (total + 1) / 2;

        int low = 1;
        int high = n;
        int ans = n;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(atMost(nums, mid) >= need) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};