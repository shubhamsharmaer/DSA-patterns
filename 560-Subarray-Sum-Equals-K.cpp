class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int> f;
        f[0] = 1;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            // get new sum
            sum += nums[i];
            // if map has this sum - k?
            int ques = sum - k;
            int freq = f[ques];
            // check if map has this or not
            if (freq > 0) {
                ans += freq;
            }
            // update map
            f[sum]++;
        }
        return ans;
    }
};