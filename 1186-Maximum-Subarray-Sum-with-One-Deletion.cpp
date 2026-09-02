class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int nodelete = arr[0];
        int onedelete = INT_MIN;
        int ans = arr[0];

        for(int i = 1; i < n; i++) {
            int prevnodel = nodelete;
            int prevonedel = onedelete;

            nodelete = max(prevnodel + arr[i], arr[i]);

            int v2;
            if(prevonedel == INT_MIN) {
                v2 = arr[i];
            } else{
                v2 = prevonedel + arr[i];
            }
            onedelete = max(v2, prevnodel);
            ans = max(ans, max(nodelete, onedelete));
        }
        return ans;
    }
};