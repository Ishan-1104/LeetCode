class Solution {
public:

    struct T {
        long long weight;
        vector<int> selected;
    };

    int n;
    vector<vector<int>> arr;
    vector<vector<T>> dp;
    vector<vector<bool>> vis;

    int findNext(int i) {

        int l = i + 1;
        int r = n;

        while (l < r) {

            int mid = l + (r - l) / 2;

            if (arr[mid][0] > arr[i][1])
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }

    T solve(int i, int cnt) {

        if (i >= n || cnt == 4)
            return {0, {}};

        if (vis[i][cnt])
            return dp[i][cnt];

        vis[i][cnt] = true;

        // Skip
        T skip = solve(i + 1, cnt);

        // Take
        int j = findNext(i);

        T next = solve(j, cnt + 1);

        T take;
        take.weight = arr[i][2] + next.weight;

        take.selected = next.selected;
        take.selected.push_back(arr[i][3]);

        // Important:
        // final answer must be compared by original indices
        sort(take.selected.begin(), take.selected.end());

        // Choose better
        if (take.weight > skip.weight) {

            dp[i][cnt] = take;

        }
        else if (take.weight < skip.weight) {

            dp[i][cnt] = skip;

        }
        else {

            // Same weight -> lexicographically smaller indices
            if (take.selected < skip.selected)
                dp[i][cnt] = take;
            else
                dp[i][cnt] = skip;
        }

        return dp[i][cnt];
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        n = intervals.size();

        arr.clear();

        for (int i = 0; i < n; i++) {

            arr.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by start time
        sort(arr.begin(), arr.end());

        dp.resize(n, vector<T>(5));
        vis.assign(n, vector<bool>(5, false));

        return solve(0, 0).selected;
    }
};