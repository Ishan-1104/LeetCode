class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char , int> mp;
        int bulls = 0;
        int cows = 0;

        for(int i = 0 ; i < secret.size() ; i++){
            if(secret[i] == guess[i])
                bulls++;
            else
                mp[secret[i]]++;
        }

        for(int i = 0 ; i < guess.size() ; i++){
            if(secret[i] == guess[i])
                continue;
            
            if(mp[guess[i]] > 0){
                cows++;
                mp[guess[i]]--;
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};