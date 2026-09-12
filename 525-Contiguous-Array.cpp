class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int zeroCount = 0;
        int oneCount = 0;
        int ans = 0;
        unordered_map<int, int> f;

        for(int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zeroCount++;
            }
            else {
                oneCount++;
            }

            int diff = zeroCount - oneCount;
            if(diff == 0) {
                ans = max(ans, i+1);
                continue;
            }
            if(f.count(diff)) {
                int len = i - f[diff];
                ans = max(ans, len);
            }
            else {
                f[diff] = i;
            }
        }
        return ans;
    }
};