class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // using kadane's algo
        int n =nums.size();
        int minprod = nums[0];
        int maxprod = nums[0];
        int ans = nums[0];

        for(int i = 1; i<n; i++) {
            int v1 = nums[i];
            int v2 = nums[i] * minprod;
            int v3 = nums[i] * maxprod;

            minprod = min(v1, min(v2, v3));
            maxprod = max(v1, max(v2, v3));
            ans = max(ans, max(minprod, maxprod));
        }
        return ans;
    }
};