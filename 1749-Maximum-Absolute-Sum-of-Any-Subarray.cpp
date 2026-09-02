class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxsum = nums[0];
        int minsum = nums[0];
        int ans = nums[0];

        int n = nums.size();
        if (n == 1) return abs(ans);
        for(int i = 1; i < n; i++){
            int prevmax = maxsum;
            int prevmin = minsum;

            maxsum = max(prevmax + nums[i], nums[i]);
            minsum = min(prevmin + nums[i], nums[i]);

            ans = max(abs(ans), max(abs(maxsum), abs(minsum)));
        }

        return ans;
    }
};