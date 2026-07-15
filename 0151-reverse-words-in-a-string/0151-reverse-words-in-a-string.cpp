class Solution {
public:
    string reverseWords(string s) {
        string temp;

        // Remove leading, trailing and extra spaces
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                temp += s[i];
            } else if (!temp.empty() && temp.back() != ' ') {
                temp += ' ';
            }
        }

        if (!temp.empty() && temp.back() == ' ')
            temp.pop_back();

        reverse(temp.begin(), temp.end());

        int start = 0;
        for (int end = 0; end <= temp.size(); end++) {
            if (end == temp.size() || temp[end] == ' ') {
                reverse(temp.begin() + start, temp.begin() + end);
                start = end + 1;
            }
        }

        return temp;
    }
};