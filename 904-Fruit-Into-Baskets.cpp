class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low = 0;
        int high = 0;
        int n = fruits.size();

        unordered_map<int, int> map;
        int ans = INT_MIN;

        for(high = 0; high < n; high++) {
            // store in map all fruits frequencies
            map[fruits[high]]++;

            // untill galat info correct it
            while(map.size() > 2) {
                map[fruits[low]]--;
                if(map[fruits[low]] == 0) {
                    map.erase(fruits[low]);
                }
                // update the low;
                low++;
            }

            // here two case either map size == 2 or < 2 
            // we want both as at most 2 is asked
            if (map.size() <= 2) {
                int len = high - low + 1;
                ans = max(ans, len);
            }
        }
        return ans;
    }
};