class Solution {
public:
    int nextIdx(int i, vector<int>& nums) {
        int n = nums.size();
        return ((i + nums[i])%n + n)%n;
    }
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int slow = i;
            int fast = i;
            bool forward = nums[i] > 0;
            while((nums[slow] > 0) == forward and (nums[fast] > 0) == forward and nums[nextIdx(fast, nums)] > 0 == forward){ 
                slow = nextIdx(slow, nums);
                fast = nextIdx(nextIdx(fast, nums), nums);

                if (slow == fast){
                    int sameslow = nextIdx(slow, nums);
                    if (slow == sameslow) break;
                    return true;
                };
                }
        }

        return false;
    }
};