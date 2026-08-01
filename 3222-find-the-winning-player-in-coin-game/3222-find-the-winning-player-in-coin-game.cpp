class Solution {
public:
    string winningPlayer(int x, int y) {
        string player1 = "Alice";
        string player2 = "Bob";

        int count = 0;

        while (x >= 0 && y >= 0) {
            x = x - 1;
            y = y - 4;
            count++;
        }

        if (count % 2 == 0)
            return player1;
        else
            return player2;
    }
};