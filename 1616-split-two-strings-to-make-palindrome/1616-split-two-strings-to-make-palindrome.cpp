class Solution {
public:
    bool palindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;

            l++;
            r--;
        }
        return true;
    }

    bool check(string& a, string& b) {
        int l = 0;
        int r = b.size() - 1;

        while (l < r && a[l] == b[r]) {
            l++;
            r--;
        }

        return palindrome(a, l, r) || palindrome(b, l, r);
    }

    bool checkPalindromeFormation(string a, string b) {
        if (check(a, b))
            return true;
        if (check(b, a))
            return true;

        return false;
    }
};