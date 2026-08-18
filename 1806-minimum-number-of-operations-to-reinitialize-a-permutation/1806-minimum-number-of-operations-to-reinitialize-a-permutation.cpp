class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> perm(n);

        for (int i = 0; i < n; i++) {
            perm[i] = i;
        }

        vector<int> arr(n);
        int count = 0;

        while (true) {

            for (int i = 0; i < n; i++) {

                if (i % 2 == 0)
                    arr[i] = perm[i / 2];
                else
                    arr[i] = perm[n / 2 + (i - 1) / 2];
            }

            count++;
            perm = arr;

            bool same = true;

            for (int i = 0; i < n; i++) {
                if (perm[i] != i) {
                    same = false;
                    break;
                }
            }

            if (same)
                return count;
        }
    }
};