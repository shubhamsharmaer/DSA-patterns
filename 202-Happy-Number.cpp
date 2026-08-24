class Solution {
public:
    int sumSqr(int n) {
        int sum = 0;
        while(n > 0) {
            int d = n % 10;
            n /= 10;
            sum = sum + (d * d);
        }
        return sum;
    }
    bool isHappy(int n) {
       int slow = n;
       int fast = n;

       while(fast != 1){
        // move both
        slow = sumSqr(slow);
        fast = sumSqr(fast);
        fast = sumSqr(fast);

        if(slow == fast and slow != 1) {
            return false;
        }
       }
       return true;
    }
};