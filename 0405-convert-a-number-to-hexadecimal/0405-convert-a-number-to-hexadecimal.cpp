class Solution {
public:
    string toHex(int num) {
        string hex = "0123456789abcdef";
        string ans;

        if(num == 0)
            return "0";

        unsigned int n = num;

        while (n > 0) {
            int digit = n % 16;
            ans += hex[digit];
            n /= 16;
        }

        reverse(ans.begin() , ans.end());

        return ans;
    }
};