class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        if(b == "")
            return 0;
        
        string temp = a;
        int count = 1;

        while(temp.size() < b.size()){
            temp += a;
            count++;
        }

        if(temp.find(b) != string :: npos){
            return count;
        }

        temp += a;
        count ++;

        if(temp.find(b) != string::npos){
            return count;
        }

        return -1;
    }
};