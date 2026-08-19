class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans = 2 * n;

        unordered_map<int, vector<int>> reserved;

        for (auto& seat : reservedSeats) {
            reserved[seat[0]].push_back(seat[1]);
        }

        for (auto& [row, seat] : reserved) {
            bool left = true;
            bool right = true;
            bool middle = true;

            for (int s : seat) {
                if (s >= 2 && s <= 5)
                    left = false;
                if (s >= 4 && s <= 7)
                    middle = false;
                if (s >= 6 && s <= 9)
                    right = false;
            }

            if (left && right)
                continue;
            else if (left || right || middle)
                ans -= 1;
            else
                ans -= 2;
        }
        return ans;
    }
};