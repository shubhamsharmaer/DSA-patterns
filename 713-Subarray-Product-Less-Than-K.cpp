class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0;
        int high = 0;
        int ans = 0;
        int product = 1;
        for(high = 0; high < n; high++){
            // inlcude high in info
            product *= nums[high];

            while(product >= k and low < n) {
                product /= nums[low];
                low++;
            }
            ans += high - low + 1;
        }
        return ans;
    }
};