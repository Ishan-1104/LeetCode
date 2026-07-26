class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words,
                                         char separator) {
        vector<string> ans;
        string temp = "";
        for (int i = 0; i < words.size(); i++) {
            temp = "";
            for (char ch : words[i]) {
                if (ch != separator) {
                    temp += ch;
                } else {
                    if (!temp.empty()) {
                        ans.push_back(temp);
                        temp = "";
                    }
                }
            }
            if (!temp.empty()) {
                ans.push_back(temp);
            }
        }
        return ans;
    }
};