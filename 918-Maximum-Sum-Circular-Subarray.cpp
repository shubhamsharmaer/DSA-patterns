class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int bestmax = nums[0];
        int maxend = nums[0];
        int bestmin = nums[0];
        int minend = nums[0];
        int totalsum = nums[0];

        for(int i = 1; i<n; i++){
            totalsum += nums[i];
            maxend = max(maxend + nums[i], nums[i]);
            bestmax = max(bestmax, maxend);

            minend = min(minend + nums[i], nums[i]);
            bestmin = min(bestmin, minend);
        }
        if (bestmax < 0) return bestmax;
        return max(bestmax, totalsum - bestmin);
    }
};