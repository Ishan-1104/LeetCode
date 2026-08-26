class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();

        for(int i = 1 ; i <= n/2 ; i++){
            string temp = s.substr(0,i);

            while(temp.size() < s.size()){
                temp += s.substr(0,i);
            }

            if(temp == s)
                return true;
        }
        return false;
    }
};