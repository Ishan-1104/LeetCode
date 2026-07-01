class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        string ans = "";

        if (n > m)
            return ans;

        unordered_map<char, int> tfreq;
        unordered_map<char, int> sfreq;

        for (char ch : t) {
            tfreq[ch]++;
        }

        int left = 0;
        int start = 0;
        int minLen = INT_MAX;
        int matched = 0;

        for (int right = 0; right < m; right++) {
            sfreq[s[right]]++;

            if (tfreq.count(s[right]) && sfreq[s[right]] <= tfreq[s[right]])
                matched++;

            while (matched == n) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                sfreq[s[left]]--;

                if (tfreq.count(s[left]) && sfreq[s[left]] < tfreq[s[left]]) {
                    matched--;
                }

                left++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};