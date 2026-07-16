class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx = 0;
        vector<int>prefixGcd;

        for(int i = 0 ; i < nums.size() ; i++){
            mx = max(nums[i] , mx);
            prefixGcd.push_back(gcd(nums[i] , mx));
        }

        sort(prefixGcd.begin() , prefixGcd.end());

        long long sum = 0;
        int left = 0 ;
        int right = nums.size()-1;

        while(left < right){
            sum += gcd(prefixGcd[left] , prefixGcd[right]);
            left++;
            right--;
        }

        return sum;
    }
};