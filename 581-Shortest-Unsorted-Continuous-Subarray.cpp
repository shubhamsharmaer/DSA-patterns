class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left  = 0;
        int n = nums.size();
        int right = n - 1;
        int leftmost = 0;
        int rightmost = 0;

        while(left + 1 < n) {
            if (nums[left] > nums[left + 1]) {
                leftmost = left;
                break;
            }
            else {
                left++;
            }
        }

          while(right - 1 >= 0) {
            if (nums[right] < nums[right - 1]) {
                rightmost = right;
                break;
            }
            else {
                right--;
            }
        }

        if (leftmost == rightmost) return rightmost - leftmost;

        // find min and max
        int minV = nums[leftmost];
        int maxV = nums[rightmost];
        for (int i = leftmost; i <= rightmost; i++) {
            minV = min(minV, nums[i]);
            maxV = max(maxV, nums[i]);
        }
        // extend range
        while(leftmost - 1 >= 0 and nums[leftmost - 1] > minV) {
            leftmost--;
        }
        while(rightmost + 1 < n and nums[rightmost + 1] < maxV) {
            rightmost++;
        }
        return rightmost - leftmost + 1;
    }
};