class Solution {
public:

    int nCr(int n, int r){
    
    double sum = 1;

    // Calculate the value of n choose
    // r using the binomial coefficient formula
    for (int i = 1; i <= r; i++){
        
        sum = sum * (n - r + i) / i;
    }
    return (int)sum;
}

    string kthSmallestPath(vector<int>& destination, int k) {
        int h = destination[1];
        int v = destination[0];

        string ans = "";

        while(h > 0 || v > 0){
            if(h == 0){
                ans += 'V';
                v--;
                continue;
            }

            if(v == 0){
                ans += 'H';
                h--;
                continue;
            }

            int cnt = nCr(v+h-1 , v);
            if(k <= cnt){
                ans += 'H';
                h--;
            }else{
                ans += 'V';
                 k -= cnt;
                 v--;
            }
        }

        return ans;
    }
};