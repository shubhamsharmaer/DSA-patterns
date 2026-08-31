class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // using kadane's algo
        int bestans = nums[0];
        int ans = nums[0];

        int n = nums.size();
        for(int i = 1; i<n; i++) {
            int v1 = bestans + nums[i];
            int v2 = nums[i];

            bestans = max(v1,v2);
            ans = max(bestans, ans);
        }
        return ans;
    }
};