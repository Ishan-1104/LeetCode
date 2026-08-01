class Solution {
public:
    unordered_map<int, bool> dp;

    bool solve(int mask, int target, int n) {
        if (dp.count(mask))
            return dp[mask];

        for (int i = 1; i <= n; i++) {
            if (mask & (1 << i))
                continue;

            if (i >= target)
                return dp[mask] = true;

            int newMask = mask | (1 << i);

            if (!solve(newMask, target - i, n))
                return dp[mask] = true;
        }

        return dp[mask] = false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0)
            return true;

        int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;

        if (sum < desiredTotal)
            return false;

        return solve(0, desiredTotal, maxChoosableInteger);
    }
};