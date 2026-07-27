class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        vector<pair<int,int>> stones;
        for(int i = 0 ; i <aliceValues.size() ; i++){
            stones.push_back({aliceValues[i]+ bobValues[i] , i});
        }

        sort(stones.rbegin() , stones.rend());

        int alice = 0;
        int bob = 0;

        for(int i = 0 ; i < stones.size(); i++){
            int idx = stones[i].second;

            if(i %2 == 0)
                alice += aliceValues[idx];
            else
                bob += bobValues[idx];
        }

        if(alice > bob)
            return 1;
        else if(alice == bob)
            return 0;
        else
            return -1;

    }
};