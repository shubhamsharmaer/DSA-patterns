class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // return subarrs whose sum are % k == 0
        // using hashmap with prefix sum
        int n = nums.size();
        unordered_map<int, int> f;
        int sum = 0;
        f[0] = 1;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = ((sum % k) + k) % k;
            int ques = f[rem];
            if (ques > 0) {
                ans += ques;
            }
            // update the map
            f[rem]++;
        }
        return ans;
    }
};