class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> odd;
        priority_queue<int> even;

        string s = to_string(num);

        for (char c : s) {
            int digit = c - '0';

            if (digit % 2 == 0)
                even.push(digit);
            else
                odd.push(digit);
        }

        int ans = 0;

        for (char c : s) {
            int digit = c - '0';

            if (digit % 2 == 0) {
                ans = ans * 10 + even.top();
                even.pop();
            }
            else {
                ans = ans * 10 + odd.top();
                odd.pop();
            }
        }

        return ans;
    }
};