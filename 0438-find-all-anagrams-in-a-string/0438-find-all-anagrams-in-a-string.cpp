class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<int> pCount(26, 0);
        vector<int> windowCount(26, 0);

        vector<int> ans;

        if (m > n)
            return ans;

        for (char ch : p)
            pCount[ch - 'a']++;

        for (int i = 0; i < m; i++) {
            windowCount[s[i] - 'a']++;
        }

        if (windowCount == pCount) {
            ans.push_back(0);
        }

        for (int i = m; i < n; i++) {
            windowCount[s[i] - 'a']++;
            windowCount[s[i - m] - 'a']--;

            if (windowCount == pCount) {
                ans.push_back(i - m + 1);
            }
        }
        return ans;
    }
};