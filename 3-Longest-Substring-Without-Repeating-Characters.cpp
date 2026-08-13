class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0, high = 0;
        int ans = INT_MIN;
        int n = s.size();
        unordered_map<char, int> map;
        for(high = 0; high < n; high++) {
            // make map
            map[s[high]]++;

            // correct galat info
            // we don't have k like other sliding window ques
            // so how can we get rid of duplicate chars

            // when map size == window size
            // NOTE: map size never > then given arr or string so we only left with 
            // == and < case and == is our answer

            // take the len of current window (high - low + 1)
            while(map.size() < high - low + 1) {
                // we need to shrink the window 
                // then we have to use low
                if(map.size() > 0) map[s[low]]--;
                if(map[s[low]] == 0) {
                    map.erase(s[low]);
                }
                low++;
            }
            if(map.size() == high - low + 1) {
                int len = high - low + 1;
                ans = max(ans, len);
            }
        }
        if (ans == INT_MIN) {
            return 0;
        }
        return ans;
    }
};