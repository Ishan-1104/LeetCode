class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        vector<int> s1Count(26,0);
        vector<int> windowCount(26,0);

        if(m>n)  return false;

        for(char ch:s1){
            s1Count[ch-'a']++;
        }

        for(int i = 0 ; i < m ; i++){
            windowCount[s2[i] -'a']++;
        }

        if(s1Count == windowCount)  return true;

        for(int i = m ; i < n ; i++){
            windowCount[s2[i]-'a']++;
            windowCount[s2[i-m]-'a']--;

            if(s1Count == windowCount) return true;
        }

        return false;
    }
};