class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // sliding window
        // init low, high both at 0
        int low = 0;
        int high = 0;

        // take a res 
        int res = INT_MAX;
        int n = nums.size();
        int sum = 0;
        int len = 0;
        while(high < n) {
            // take first sum
            sum = sum + nums[high];

            // take a while loop to decrease the window untill its working for target
            while (sum >= target) {
                // take the len of window
                len = high - low + 1;
                // get the min len
                res = min(res, len);
                // fire the people/element
                sum = sum - nums[low];
                low++;
            }
            // increase the window 
            high++;
        }   
        if(len == 0) return 0;
        return res;
    }
};