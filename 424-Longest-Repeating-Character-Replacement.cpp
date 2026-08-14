class Solution {
public:
    int find(vector<int> a) {
        int maxCount = -1;
        for(int i = 0; i< 256; i++) {
            maxCount = max(maxCount, a[i]);
        }
        return maxCount;
    }
    int characterReplacement(string s, int k) {
        int low = 0, high = 0;
        int ans = INT_MIN;
        int n = s.size();

        vector<int> f(256, 0);
        for(high = 0; high < n; high++) {
            // include high
            f[s[high]]++;
            // now cal 3 things:
            // current window len
            int len = high - low + 1;
            // maxCount from f
            int maxCount = find(f);
            // diff
            int diff = len - maxCount;

            // galat info correction
            while(diff > k) {
                f[s[low]]--;
                low++;
                // update all 3 values depends upon low
                len = high - low + 1;
                maxCount = find(f);
                diff = len - maxCount;
            }
            // here 2 cases possible
            // diff < k or == k
            // we want both as our ans
            len = high - low + 1;
            ans = max(ans, len);
        }
        
        return ans;
    }
};