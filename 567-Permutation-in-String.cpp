class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        
        if (n > m) return false;

        // make freq for s1
        vector<int> target(128, 0);
        vector<int> window(128, 0);

        // sliding window vars
        int low = 0;
        int high = n - 1;

        for(int i = 0; i<n; i++){
            target[s1[i]]++;
            window[s2[i]]++;
        }

        while(high < m) {
            
            // check if target and window matches
            if(window == target) return true;

            window[s2[low]]--;
            low++;
            high++;
            window[s2[high]]++;
        }
        return false;
    }
};