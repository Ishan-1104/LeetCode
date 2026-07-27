class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char , int > freq;

        for(char ch : s){
            freq[ch]++;
        }

        vector<int> value;

        for( auto &f : freq){
            value.push_back(f.second);
        }

        sort(value.rbegin() , value.rend());
        int ans = 0;

        for(int i = 1 ; i < value.size() ; i++){
            while(value[i] > 0 && value[i] >= value[i-1]){
                value[i]--;
                ans++;
            }
        }
        return ans;
    }
};