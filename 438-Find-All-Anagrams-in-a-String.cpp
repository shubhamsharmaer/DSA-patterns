class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<int> target(256, 0);
        vector<int> window(256, 0);

        for(int i = 0; i<m; i++){
            target[p[i]]++;
            window[s[i]]++;
        }
        
        int low = 0;
        int high = m - 1;

        vector<int> ans;
        while(high < n) {
            // check if both matches
            if(window == target) {
                ans.push_back(low);
            }

            // if not then slide the window
            window[s[low]]--;
            low++;

            if(high == n - 1) break;

            high++;
            window[s[high]]++;
        }
        return ans;
    }
};