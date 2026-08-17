class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        if (numFriends == 1) return word;
        
        int maxLen = n - numFriends + 1;
        string best = "";
        
        for (int i = 0; i < n; i++) {
            string candidate = word.substr(i, maxLen);
            if (candidate > best) {
                best = candidate;
            }
        }
        return best;
    }
};