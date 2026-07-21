class Solution {
public:

    bool diff(string temp){
        unordered_map<char,int> freq;

        for(char ch : temp)
            freq[ch]++;

        for(auto it : freq){
            if(it.second > 1)
                return false;
        }

        return true;
    }

    int ans = 0;

    void solve(int idx, vector<string>& arr, string temp){

        if(!diff(temp))
            return;

        ans = max(ans, (int)temp.size());

        for(int i = idx; i < arr.size(); i++){
            solve(i + 1, arr, temp + arr[i]);
        }
    }

    int maxLength(vector<string>& arr) {

        solve(0, arr, "");

        return ans;
    }
};