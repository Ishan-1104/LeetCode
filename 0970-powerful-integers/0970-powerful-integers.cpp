class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {

        set<int> st;

        for (int a = 1; a <= bound; ) {

            for (int b = 1; a + b <= bound; ) {

                st.insert(a + b);

                if (y == 1)
                    break;

                b *= y;
            }

            if (x == 1)
                break;

            a *= x;
        }

        return vector<int>(st.begin(), st.end());
    }
};